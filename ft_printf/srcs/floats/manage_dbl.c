#include "../../includes/ft_printf.h"

int	manage_dbl(t_dbl *dbl, int prec, int *to_print, char *buffer)
{
	bigint			result;
	t_bigint_info	info;
	

	if (dbl->expo >= 0)
		store_big_dbl(*dbl, &result);
	else
		store_small_dbl(*dbl, &result);
	info.is_long = 0;
	get_bigint_info(&result, dbl->expo, prec, &info);
	if (dbl->expo < 0)
		*to_print += prec > 0 ? prec + 2 : 1;
	else
	{
		if (info.first_int_case < 993)
		{
			*to_print += get_uint_len(result[info.first_int_case]);
			*to_print += (992 - info.first_int_case) * 9 + 3;
		}
		else
		{
			*to_print += get_uint_len(divide_by_10(result[info.last_int_case], 6));
		}
		*to_print += prec > 0 ? prec + 1 : 0;
	}
	return (print_dbl(dbl->expo, &result, prec, &info, buffer));
}

int	print_dbl(int16_t expo, bigint *result, int prec, t_bigint_info
	 *info, char *buffer)
{
	if (expo >= 0)
		return (print_big_dbl(expo, result, prec, info, buffer));
	return (print_small_dbl(expo, result, prec, info, buffer));
}

void	store_big_dbl(t_dbl dbl, bigint *result)
{
	bigint	unit;
	int		i;

	init_bigint(result);
	create_unit(&unit, sizeof(dbl.bits.f), dbl.expo);
	i = -1;
	while (++i < dbl.expo)
		multiply_bigint_by_2(&unit);
	i = 52;
	while (i > 0)
	{
		if (i < 52)
			multiply_bigint_by_2(&unit);
		if (dbl.mant>>(64 - i) & 0x1)
			add_bigints(result, &unit);
		i--;
	}
	multiply_bigint_by_2(&unit);
	add_bigints(result, &unit);
}

void	store_small_dbl(t_dbl dbl, bigint *result)
{
	bigint	unit;
	int		i;

	init_bigint(result);
	create_unit(&unit, sizeof(dbl.bits.f), dbl.expo);
	i = -1;
	while (--i >= dbl.expo)
		divide_bigint_by_2(&unit);
	add_bigints(result, &unit);
	i = 1;
	while (i < 53)
	{
		divide_bigint_by_2(&unit);
		if (dbl.mant>>(64 - i) & 0x1)
			add_bigints(result, &unit);
		i++;
	}
}
