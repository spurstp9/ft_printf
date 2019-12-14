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
	t_buf	buf;
	char	*p;
	int		res;

	buf.index = 0;
	res = 0;
	p = (char *)format;
	va_start(ap, format);
	while (*p)
	{
		while (*p && *p != '%')
		{
			res += putc_no_format(&buf, *p);
			p++;
		}
		if (*p == '%')
		{
			res += print_format_string(ap, &buf, &p);
		}
	}
	print_buffer(&buf);
	va_end(ap);
	return (res);
}

int		print_format_string(va_list ap, t_buf *buf, char **str)
{
	static int	(*f[11]) (va_list ap, t_buf *buf, t_conv *c) = {&print_c,
		&print_d, &print_f, &print_lf, &print_o, &print_p, &print_s,
		&print_u, &print_x, &print_big_x, &print_b};
	t_conv		conv;

	(*str)++;
	if (!(**str))
		return (0);
	init_conv(&conv);
	get_conv_info(ap, str, &conv);
	//print_conv(conv);
	return (f[conv.type](ap, buf, &conv));
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
