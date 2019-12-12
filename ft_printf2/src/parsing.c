/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:33:23 by agardina          #+#    #+#             */
/*   Updated: 2019/12/11 19:35:19 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void	init_conv(t_conv *c)
{
	c->minus = 0;
	c->plus = 0;
	c->zero = 0;
	c->space = 0;
	c->hashtag = 0;
	c->width = 0;
	c->prec = -1;
	c->int_size = 0;
	c->f_size = 0;
	c->other_char = 0;
	c->type = 0;
}

void	get_conv_info(char **str, t_conv *conv)
{
	while (**str && is_conv_char(**str))
	{
		if (**str == '-')
			conv->minus = 1;
		else if (**str == '+')
			conv->plus = 1;
		else if (**str == '0')
			conv->zero = 1;
		else if (**str == ' ')
			conv->space = 1;
		else if (**str == '#')
			conv->hashtag = 1;
		else if (ft_isdigit(**str) && **str != '0')
			get_width(str, conv);
		else if (**str == '.')
			get_prec(str, conv);
		else if (is_lm(**str))
			get_length(str, conv);
		(*str)++;
	}
	if (**str)
		get_type(str, conv);
	set_prio_flags(conv);
}

void	get_prec(char **str, t_conv *conv)
{
	(*str)++;
	conv->prec = 0;
	if (**str)
	{
		while (**str && ft_isdigit(**str))
		{
			conv->prec = (conv->prec * 10) + **str - '0';
			(*str)++;
		}
	}
	(*str)--;
}

int		is_conv_char(char c)
{
	return (is_lm(c) || ft_isdigit(c) || c == '.' || c == '-'
			|| c == '#' || c == '+' || c == ' ');
}

void	get_width(char **str, t_conv *conv)
{
	conv->width = 0;
	while (**str && ft_isdigit(**str))
	{
		conv->width = (conv->width * 10) + **str - '0';
		(*str)++;
	}
	(*str)--;
}
