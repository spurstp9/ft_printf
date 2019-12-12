#include "../../includes/ft_printf.h"

int	get_next_figure(bigint *result, t_bigint_info info)
{
	int index_case;
	int index_fig;
	unsigned int nb;
	int i;
	
	// if (!info.last_dec_case && !info.last_digit_rank)
	// {
	// 	index_case = 1;
	// 	index_fig = 0;
	// }
	// else
	// {
		index_case = info.last_dec_case + (info.last_digit_rank == 0 ? 1 : 0);
		index_fig = info.last_digit_rank + 1;
	// }
	nb = (*result)[index_case];
	i = 0;
	while (i < 9 - index_fig)
	{
		nb /= 10;
		i++;
	}
	return (nb % 10);
}

int get_last_dec_case(int16_t expo, int prec, t_bigint_info info)
{
	int first_case;
	int res;
	
	first_case = info.first_dec_case;
	if (!prec)
		return ((expo >= 0 && !info.is_long) ? first_case : first_case - 1);
	if (expo >= 0 && !info.is_long)
	{
		res = first_case;
		res += (prec - 6 > 0) ? ((prec - 6) / 9) : 0;
		res += ((prec - 6) % 9) > 0 ? 1 : 0;
	}
	else
		res = (prec / 9) + (prec % 9 ? 1 : 0) + (info.is_long && expo >= 0 ? 992 : 0);
	return (res);
}

int	get_last_digit_rank(int16_t expo, int prec, t_bigint_info info)
{
	int res;
	
	if (expo >= 0 && !info.is_long)
		res = (prec <= 6 ? prec + 3 : ((prec - 6) % 9));
	else
		res = prec % 9;
	return (res);
}

int get_first_int_case(int16_t expo, t_bigint_info *info, bigint *result)
{
	int i;

	i = 0;
	if (expo < 0)
		info->first_int_case = 0;
	else
	{
		while ((*result)[i] == 0)
			i++;
		info->first_int_case = i;
	}
	return (0);
}
