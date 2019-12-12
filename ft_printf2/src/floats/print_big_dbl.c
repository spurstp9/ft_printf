/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_big_dbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:06:14 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 20:07:36 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prototypes.h"

int		print_big_dbl(int16_t expo, t_conv *conv, t_bigint *big,
	t_buf *buf)
{
	int				res;
    unsigned int last_case_to_print;

    last_case_to_print = (big->tab)[big->last_dec_case];
    cut_tab(big);
    round_up_bigint(big, last_case_to_print);
	res = print_int_part(big, expo, conv->prec, buf);
	if (conv->prec || conv->hashtag)
		putc_no_format(buf, '.');
	if (conv->prec)
		print_dec_part(big, conv->prec, expo, buf);
	return (res + (conv->prec > 0 ? conv->prec + 1 : 0));
}

void	print_first_dec(unsigned int nb, int *prec, int *index, t_buf *buf)
{
	int	i;
	int	len;
	int	mod;
	int	min;

	i = 0;
	mod = 1;
	min = ft_min(*prec, 6);
	if ((len = get_uint_len(nb)) > min)
	{
		while (i < min)
		{
			mod *= 10;
			i++;
		}
		nb = nb % mod;
	}
	put_zeros(min - get_uint_len(nb), buf);
	ft_putnbr_buf(buf, nb);
	*prec -= min;
	(*index)++;
}
