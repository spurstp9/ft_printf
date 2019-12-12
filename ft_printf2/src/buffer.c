/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:23:46 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:23:52 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void	print_buffer(t_buf *buf)
{
	write(1, buf->b, buf->index);
}

int		putc_no_format(t_buf *buf, char c)
{
	if (buf->index == BUFF_SIZE - 1)
	{
		print_buffer(buf);
		buf->index = 0;
	}
	buf->b[buf->index] = c;
	(buf->index)++;
	return (1);
}

void	puts_no_format(t_buf *buf, char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		putc_no_format(buf, str[i]);
		i++;
	}
}

void	put_spaces(int nb, t_buf *buf)
{
	int count;

	count = nb;
	if (count > 0)
	{
		while (count--)
			putc_no_format(buf, ' ');
	}
}

void	put_zeros(int nb, t_buf *buf)
{
	int count;

	count = nb;
	if (count > 0)
	{
		while (count--)
			putc_no_format(buf, '0');
	}
}
