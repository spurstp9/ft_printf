/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:36:50 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 12:36:53 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void	get_type(char **str, t_conv *conv)
{
	if (**str == 'X')
		conv->type = TYPE_BIG_X;
	else if (**str == 'x')
		conv->type = TYPE_X;
	else if (**str == 'u')
		conv->type = TYPE_U;
	else if (**str == 's')
		conv->type = TYPE_S;
	else if (**str == 'p')
		conv->type = TYPE_P;
	else if (**str == 'o')
		conv->type = TYPE_O;
	else if (**str == 'f' && !conv->f_size)
		conv->type = TYPE_F;
	else if (**str == 'f' && conv->f_size)
		conv->type = TYPE_LF;
	else if (**str == 'b')
		conv->type = TYPE_B;
	else if (**str == 'd' || **str == 'i')
		conv->type = TYPE_D;
	else
	{
		conv->type = TYPE_C;
		conv->other_char = **str != 'c' ? **str : 0;
	}
	(*str)++;
}

void	get_length(char **str, t_conv *conv)
{
	int	new_int_size;
	int	new_f_size;

	new_int_size = 0;
	new_f_size = 0;
	while (**str && is_lm(**str))
	{
		if (**str == 'h' && *(*str + 1) == 'h')
			new_int_size = SIZE_HH;
		else if (**str == 'h')
			new_int_size = SIZE_H;
		else if (**str == 'l' && *(*str + 1) == 'l')
			new_int_size = SIZE_LL;
		else if (**str == 'l')
			new_int_size = SIZE_L;
		else if (**str == 'L')
			new_f_size = SIZE_LF;
		conv->int_size = ft_max(new_int_size, conv->int_size);
		conv->f_size = ft_max(new_f_size, conv->f_size);
		(*str)++;
		if (new_int_size == SIZE_HH || new_int_size == SIZE_LL)
			(*str)++;
	}
	(*str)--;
}

int		is_lm(char c)
{
	return (c == 'h' || c == 'l' || c == 'L');
}

int		is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
			|| c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f');
}

void	set_prio_flags(t_conv *conv)
{
	if (conv->type != TYPE_B)
	{
		if (conv->zero && conv->minus)
			conv->zero = 0;
		if (conv->space && conv->plus)
			conv->space = 0;
		if (conv->prec > -1 && (conv->type == TYPE_D || conv->type == TYPE_O
					|| conv->type == TYPE_U || conv->type == TYPE_X
					|| conv->type == TYPE_BIG_X))
			conv->zero = 0;
	}
}
