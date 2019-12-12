#include "../../includes/ft_printf.h"

int	print_int_part(bigint *result, int16_t expo, int prec, t_bigint_info info, char *buffer)
{
	int i;
	unsigned int last_digits;
	int int_part_start;
	int res;
	
	if (expo < 0)
	{
		ft_putnbr((*result)[0]);
		return (1);
	}
	else
	{
		res = 0;
		i = 0;
		while ((*result)[i] == 0)
			i++;
		int_part_start = i;
		while (i < BIGINT_SIZE - 7)
		{
				if (i == int_part_start)
					res += get_uint_len((*result)[i]);
				else
					res += 9;
				if (i > int_part_start)
					filling_zeros((*result)[i]);
				if ((*result)[i])
					ft_putnbr((*result)[i]);
			i++;
		}
		if (!info.is_long)
		{
			last_digits = (*result)[993];
			last_digits = divide_by_10(last_digits, ft_min(prec, 6)); //Enlever les chiffres décimaux
			if (int_part_start < 993)
				put_zeros(3 - get_uint_len(last_digits), buffer); //Afficher les 0 de la partie entière
			if (last_digits > 0)
				ft_putnbr(last_digits);
			res += get_uint_len(last_digits);
		}
		return (res);
	}
}

void get_prec_to_add(bigint *to_add, int index)
{
	init_bigint(to_add);
	(*to_add)[index] = 1;
}

void	cut_result(bigint *result, t_bigint_info info)
{
	int i;
	
	i = info.last_dec_case;
	(*result)[i] = divide_by_10((*result)[i], info.last_digit_rank > 0 ? 9 - info.last_digit_rank : 0);
	i++;
	while (i < BIGINT_SIZE)
	{
		(*result)[i] = 0;
		i++;
	}
}

void	get_bigint_info(bigint *result, int16_t expo, int prec, t_bigint_info *info)
{
	get_first_int_case(expo, info, result);
	if (expo < 0)
		info->last_int_case = 0;
	else
		info->last_int_case = info->is_long ? 992 : 993;
	info->first_dec_case = expo >= 0 ? 993 : 1;
	info->last_dec_case = get_last_dec_case(expo, prec, *info);
	info->last_digit_rank = get_last_digit_rank(expo, prec, *info);
	info->next_figure = get_next_figure(result, *info);
}

void	print_dec_part(bigint *result, t_bigint_info info, int prec, int16_t expo, char *buffer)
{
	int i;
	
	write(1, ".", 1);
	i = (expo >= 0 ? 993 : 1);
	if (expo >= 0 && !info.is_long)
		print_first_dec((*result)[993], &prec, &i, buffer);
//	if (!(expo >= 0 && !info.is_long && prec < 9))
//	{
		while (i <= info.last_dec_case)
		{
			if (i < info.last_dec_case || info.last_digit_rank == 0)
			{
				filling_zeros((*result)[i]);
				if ((*result)[i])
					ft_putnbr((*result)[i]);
				prec -= 9;
			}
			i++;
		}
		if (prec > 0 && info.last_digit_rank > 0)
		{
				put_zeros(prec - get_uint_len((*result)[i - 1]), buffer);
				if ((*result)[i - 1])
					ft_putnbr((*result)[i - 1]);
		}
//	}
}
