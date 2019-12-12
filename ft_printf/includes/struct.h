#ifndef STRUCT_H

# define STRUCT_H

typedef struct 	s_conv
{
	char 		align;
	char 		sign;
	char 		fill;
	char 		space;
	char 		hashtag;
	int 		width;
	int 		prec;
	int 		size;
	char 		type;
}				t_conv;

typedef union   u_dbl_bits
{
    double      f;
    uint64_t    u;
}               t_dbl_bits;

typedef struct	s_dbl
{
	t_dbl_bits	bits;
	int16_t		expo;
	uint64_t	mant;
}				t_dbl;

typedef union   u_ldbl_bits
{
	long double	f;
	uint16_t	u[8];
}               t_ldbl_bits;

typedef struct	s_ldbl
{
	t_ldbl_bits	bits;
	int16_t		expo;
	uint64_t	mant;
}				t_ldbl;

/*
** Chaque case du tableau peut contenir un nombre entre 0 et 2 147 483 647.
** On limite la valeur de chaque case à 999 999 999.
*/

typedef unsigned int bigint[BIGINT_SIZE]; 

typedef struct	s_bigint_info
{
	int			first_int_case;
	int			last_int_case;
	int			first_dec_case;
	int			last_dec_case;
	int			last_digit_rank;
	int			next_figure;
	int			is_long;
}				t_bigint_info;

#endif
