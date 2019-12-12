/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:25:49 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:26:41 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

int		print_x(va_list ap, t_buf *buf, t_conv *conv)
{
	unsigned long long int	nb;
	unsigned int			len;
	int						prefix_len;

	nb = convert_u_number(ap, conv);
	len = (!nb && !conv->prec) ? 0 : get_convert_len(nb, conv);
	prefix_len = nb > 0 && conv->hashtag ? 2 : 0;
	if (!conv->minus && conv->width > 0 && !conv->zero)
		put_spaces(conv->width - ft_max(len, conv->prec) - prefix_len, buf);
	print_u_prefix(nb, conv, buf);
	if (conv->prec > -1 || conv->zero)
	{
		if (conv->prec > -1)
			put_zeros(conv->prec - len, buf);
		else
			put_zeros(conv->width - len - prefix_len, buf);
	}
	if (len)
		ft_putnbr_base_buf(buf, nb, "0123456789abcdef");
	if (conv->minus)
		put_spaces(conv->width - ft_max(len, conv->prec) - prefix_len, buf);
	return (ft_max(ft_max(len + prefix_len, conv->prec), conv->width));
}

int		print_big_x(va_list ap, t_buf *buf, t_conv *conv)
{
	unsigned long long int	nb;
	unsigned int			len;
	int						prefix_len;

	nb = convert_u_number(ap, conv);
	len = (!nb && !conv->prec) ? 0 : get_convert_len(nb, conv);
	prefix_len = nb > 0 && conv->hashtag ? 2 : 0;
	if (!conv->minus && conv->width > 0 && !conv->zero)
		put_spaces(conv->width - ft_max(len, conv->prec) - prefix_len, buf);
	print_u_prefix(nb, conv, buf);
	if (conv->prec > -1 || conv->zero)
	{
		if (conv->prec > -1)
			put_zeros(conv->prec - len, buf);
		else
			put_zeros(conv->width - len - prefix_len, buf);
	}
	if (len)
		ft_putnbr_base_buf(buf, nb, "0123456789ABCDEF");
	if (conv->minus)
		put_spaces(conv->width - ft_max(len, conv->prec) - prefix_len, buf);
	return (ft_max(ft_max(len + prefix_len, conv->prec), conv->width));
}
