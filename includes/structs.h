/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:07:47 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 14:07:49 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef struct	s_conv
{
	char		minus;
	char		plus;
	char		zero;
	char		space;
	char		hashtag;
	int			width;
	int			prec;
	int			int_size;
	int			f_size;
	char		other_char;
	int			type;
}				t_conv;

typedef struct	s_buf
{
	int			index;
	char		b[BUFF_SIZE + 1];
}				t_buf;

typedef union	u_dbl_bits
{
	double		f;
	uint64_t	u;
}				t_dbl_bits;

typedef struct	s_dbl
{
	t_dbl_bits	bits;
	int			sign;
	int16_t		expo;
	uint64_t	mant;
}				t_dbl;

typedef union	u_ldbl_bits
{
	long double	f;
	uint16_t	u[8];
}				t_ldbl_bits;

typedef struct	s_ldbl
{
	t_ldbl_bits	bits;
	int			sign;
	int16_t		expo;
	uint64_t	mant;
}				t_ldbl;

/*
** Chaque case du tableau peut contenir un nombre entre 0 et 2 147 483 647.
** On limite la valeur de chaque case à 999 999 999.
*/

typedef unsigned int	t_bigtab[BIGINT_SIZE];

typedef struct	s_bigint
{
	t_bigtab	tab;
	int			first_int_case;
	int			last_int_case;
	int			first_dec_case;
	int			last_dec_case;
	int			last_digit_rank;
	int			next_figure;
	int			is_long;
}				t_bigint;

#endif
