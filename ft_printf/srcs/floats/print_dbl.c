#include "../../includes/ft_printf.h"

int	print_small_dbl(int16_t expo, bigint *result, int prec, t_bigint_info *info, char *buffer)
{
	bigint prec_to_add;
	unsigned int last_case_to_print;
	int index;

	last_case_to_print = (*result)[info->last_dec_case];
	cut_result(result, *info);
	if (info->next_figure > 4)
	{
		if (get_uint_len(last_case_to_print) == 9 && only_nine((*result)[info->last_dec_case]))
		{
			(*result)[info->last_dec_case] = 0;
			index = info->last_dec_case - 1;
		}
		else
			index = info->last_dec_case;
		get_prec_to_add(&prec_to_add, index);
		add_bigints(result, &prec_to_add);
	}
	print_int_part(result, expo, prec, *info, buffer);
	if (prec)
		print_dec_part(result, *info, prec, expo, buffer);
	return (1 + (prec > 0 ? prec + 1 : 0));
}
