/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:18:30 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 11:19:21 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prototypes.h"

int		print_small_dbl(int16_t expo, t_conv *conv, t_bigint *big, t_buf *buf)
{
    unsigned int last_case_to_print;
    
    last_case_to_print = (big->tab)[big->last_dec_case];
	cut_tab(big);
	round_up_bigint(big, last_case_to_print);
	print_int_part(big, expo, conv->prec, buf);
	if (conv->prec || conv->hashtag)
		putc_no_format(buf, '.');
	if (conv->prec)
		print_dec_part(big, conv->prec, expo, buf);
	return (1 + (conv->prec > 0 ? conv->prec + 1 : 0));
}
