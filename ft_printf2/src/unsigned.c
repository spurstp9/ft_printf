/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:41:28 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:54:26 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

int						print_u(va_list ap, t_buf *buf, t_conv *conv)
{
	unsigned long long int	nb;
	unsigned int			len;

	nb = convert_u_number(ap, conv);
	len = (!nb && !conv->prec) ? 0 : get_uint_len(nb);
	if (!conv->minus && conv->width > 0 && !conv->zero)
		put_spaces(conv->width - ft_max(len, conv->prec), buf);
	if (conv->prec > -1 || conv->zero)
	{
		if (conv->prec > -1)
			put_zeros(conv->prec - len, buf);
		else
			put_zeros(conv->width - len, buf);
	}
	if (len)
		ft_putnbr_buf(buf, nb);
	if (conv->minus)
		put_spaces(conv->width - ft_max(len, conv->prec), buf);
	return (ft_max(ft_max(len, conv->prec), conv->width));
}

void					print_u_prefix(unsigned long long nb, t_conv *conv,
		t_buf *buf)
{
	if (conv->type == TYPE_O && conv->hashtag)
		putc_no_format(buf, '0');
	else if (((conv->type == TYPE_X && conv->hashtag && nb)
				|| conv->type == TYPE_P))
	{
		putc_no_format(buf, '0');
		putc_no_format(buf, 'x');
	}
	else if (conv->type == TYPE_BIG_X && conv->hashtag && nb)
	{
		putc_no_format(buf, '0');
		putc_no_format(buf, 'X');
	}
}

unsigned long long int	convert_u_number(va_list ap, t_conv *conv)
{
	long long int	nb;

	nb = va_arg(ap, long long int);
	if (conv->int_size == SIZE_LL || conv->type == TYPE_P)
		return ((unsigned long long)nb);
	else if (conv->int_size == SIZE_L)
		return ((unsigned long)nb);
	else if (conv->int_size == SIZE_H)
		return ((unsigned short)nb);
	else if (conv->int_size == SIZE_HH)
		return ((unsigned char)nb);
	return ((unsigned int)nb);
}
