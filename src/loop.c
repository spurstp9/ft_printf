/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:29:04 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:31:56 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	t_conv	conv;
	char	*p;

	(conv.buf).index = 0;
	conv.res = 0;
	p = (char *)format;
	va_start(ap, format);
	while (*p)
	{
		if (*p && *p != '%')
			print_no_format(&conv, &p);
		if (*p && *p == '%')
			print_format_string(ap, &conv, &p);
	}
	print_buffer(&(conv.buf));
	va_end(ap);
	return (conv.res);
}

void	print_no_format(t_conv *conv, char **str)
{
	while (**str && **str != '%')
	{
		if (**str != '{')
		{
			putc_no_format(conv, **str);
			(*str)++;
		}
		else
		{
			if (!get_color(str, conv))
			{
				putc_no_format(conv, **str);
				(*str)++;
			}
		}
	}	
}

int		print_format_string(va_list ap, t_conv *conv, char **str)
{
	static int	(*f[11]) (va_list ap, t_conv *c) = {&print_c,
		&print_d, &print_f, &print_lf, &print_o, &print_p, &print_s,
		&print_u, &print_x, &print_big_x, &print_b};

	(*str)++;
	if (!(**str))
		return (0);
	init_conv(conv);
	get_conv_info(ap, str, conv);
	//print_conv(conv);
	f[conv->type](ap, conv);
	return (1);
}

void	print_conv(t_conv conv)
{
	printf("minus : %d\n", conv.minus);
	printf("plus : %d\n", conv.plus);
	printf("zero : %d\n", conv.zero);
	printf("space : %d\n", conv.space);
	printf("hashtag : %d\n", conv.hashtag);
	printf("width : %d\n", conv.width);
	printf("prec : %d\n", conv.prec);
	printf("int_size : %d\n", conv.int_size);
	printf("float_size : %d\n", conv.f_size);
	printf("type : %d\n", conv.type);
}