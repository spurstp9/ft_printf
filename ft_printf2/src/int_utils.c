/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:26:54 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:28:47 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

int					get_uint_len(unsigned long long nb)
{
	int	res;

	res = 1;
	while (nb / 10)
	{
		nb /= 10;
		res++;
	}
	return (res);
}

unsigned long long	ft_abs(long long int nb)
{
	return (nb > 0 ? nb : -nb);
}

void				ft_putnbr_buf(t_buf *buf, unsigned long long nb)
{
	if (nb / 10)
		ft_putnbr_buf(buf, nb / 10);
	putc_no_format(buf, (nb % 10) + '0');
}

void				ft_putnbr_base_buf(t_buf *buf, unsigned long long nb,
		char *base)
{
	unsigned int	len;

	len = ft_strlen(base);
	if (nb / len)
		ft_putnbr_base_buf(buf, nb / len, base);
	putc_no_format(buf, base[nb % len]);
}

int					get_convert_len(unsigned long long nb, t_conv *conv)
{
	int	res;
	int	len;

	if (conv->type == TYPE_O)
		len = 8;
	else
		len = 16;
	res = 1;
	nb /= len;
	while (nb)
	{
		res++;
		nb /= len;
	}
	return (res);
}
