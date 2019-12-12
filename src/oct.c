/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:32:09 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:32:55 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

int		print_o(va_list ap, t_buf *buf, t_conv *conv)
{
	unsigned long long int	nb;
	unsigned int			len;
	int						prefix_len;

	nb = convert_u_number(ap, conv);
	len = (!nb && (conv->prec == 0 || conv->hashtag)) ?
		0 : get_convert_len(nb, conv);
	prefix_len = conv->hashtag ? 1 : 0;
	if (!conv->minus && conv->width > 0 && !conv->zero)
		put_spaces(conv->width - ft_max(len, conv->prec) - prefix_len, buf);
	print_u_prefix(nb, conv, buf);
	if (conv->prec > -1 || conv->zero)
	{
		if (conv->prec > -1)
			put_zeros(conv->prec - len - prefix_len, buf);
		else
			put_zeros(conv->width - len - prefix_len, buf);
	}
	if (len)
		ft_putnbr_base_buf(buf, nb, "01234567");
	if (conv->minus)
		put_spaces(conv->width - ft_max(len, conv->prec) - prefix_len, buf);
	return (ft_max(ft_max(len + prefix_len, conv->prec), conv->width));
}
