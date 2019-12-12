/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:39:22 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:40:13 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

int	print_s(va_list ap, t_buf *buf, t_conv *conv)
{
	int		len;
	char	*str;

	str = (char *)va_arg(ap, char *);
	if (!conv->prec)
		len = 0;
	else if (conv->prec != 0 && !str)
		len = conv->prec == -1 ? 6 : ft_min(6, conv->prec);
	else
		len = conv->prec == -1 ? ft_strlen(str) :
			ft_min(ft_strlen(str), conv->prec);
	if (!conv->minus)
	{
		if (!conv->zero)
			put_spaces(conv->width - len, buf);
		else
			put_zeros(conv->width - len, buf);
	}
	if (!str)
		puts_no_format(buf, "(null)", len);
	else
		puts_no_format(buf, str, len);
	if (conv->minus)
		put_spaces(conv->width - len, buf);
	return (conv->width - len > 0 ? conv->width : len);
}
