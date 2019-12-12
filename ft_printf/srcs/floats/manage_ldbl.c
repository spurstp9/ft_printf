#include "../../includes/ft_printf.h"

int		manage_ldbl(t_ldbl *ldbl, int prec, int *to_print, char *buffer)
{
	bigint	result;
	t_bigint_info	info;
	
	if (ldbl->expo >= 0)
		store_big_ldbl(*ldbl, &result);
	else
		store_small_ldbl(*ldbl, & result);
	info.is_long = 1;
	get_bigint_info(&result, ldbl->expo, prec, &info);
	if (ldbl->expo < 0)
		*to_print += prec > 0 ? prec + 2 : 1;
	else
	{
		*to_print += get_uint_len(result[info.first_int_case]);
		*to_print += (992 - info.first_int_case) * 9;
		*to_print += prec > 0 ? prec + 1 : 0;
	}
	return (print_ldbl(ldbl->expo, &result, prec, &info, buffer));
}

int		print_ldbl(int16_t expo, bigint *result, int prec, t_bigint_info *info, char *buffer)
{
	if (expo >= 0)
		return (print_big_dbl(expo, result, prec, info, buffer));
	return (print_small_dbl(expo, result, prec, info, buffer));
}

void	store_big_ldbl(t_ldbl ldbl, bigint *result)
{
	bigint	unit;
	int		i;
	int		j;
	
	init_bigint(result);
	create_unit(&unit, sizeof(ldbl.bits.f), ldbl.expo);
	i = -1;
	while (++i < ldbl.expo)
		multiply_bigint_by_2(&unit);
	i = -1;
	j = 15;
	while (++i < 4)
	{
		while (j >= 0)
		{
			if (!(i == 0 && j == 15))
				multiply_bigint_by_2(&unit);
			if (ldbl.bits.u[i]>>(15 - j) & 0x1)
				add_bigints(result, &unit);
			j--;
		}
		j = 15;
	}
}

void	store_small_ldbl(t_ldbl ldbl, bigint *result)
{
	bigint	unit;
	int		i;
	int		j;

	init_bigint(result);
	create_unit(&unit, sizeof(ldbl.bits.f), ldbl.expo);
	i = -1;
	while (--i >= ldbl.expo)
		divide_bigint_by_2(&unit);
	i = 3;
	j = 0;
	while (i >= 0)
	{
		while (j <= 15)
		{
			if (ldbl.bits.u[i]>>(15 - j) & 0x1)
				add_bigints(result, &unit);
			divide_bigint_by_2(&unit);
			j++;
		}
		j = 0;
		i--;
	}
}

int		print_big_ldbl(int16_t expo, bigint *result, int prec, t_bigint_info *info, char *buffer)
{
	bigint prec_to_add;
	int res;
	unsigned int last_case_to_print;
	
	get_bigint_info(result, expo, prec, info);
	last_case_to_print = (*result)[info->last_dec_case];
	cut_result(result, *info);
	if (info->next_figure > 4)
	{
		if (last_case_to_print == 999999999)
			(*result)[info->last_dec_case] = 0;
		get_prec_to_add(&prec_to_add, (last_case_to_print == 999999999 ? info->last_dec_case - 1 : info->last_dec_case));
		add_bigints(result, &prec_to_add);
	}
	res = print_int_part(result, expo, prec, *info, buffer);
	if (prec)
		print_dec_part(result, *info, prec, expo, buffer);
	return (res + (prec > 0 ? prec + 1 : 0));
}
