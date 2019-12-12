#include "../../includes/ft_printf.h"

void    multiply_bigint_by_2(bigint *tab)
{
	unsigned int surplus;
	int i;
	
	i = BIGINT_SIZE - 1;
	surplus = 0;
	while (i >= 0)
	{
		(*tab)[i] *= 2;
		(*tab)[i] += surplus/(CELL_LIMIT + 1);
		if ((*tab)[i] > CELL_LIMIT)
		{
			surplus = CELL_LIMIT + 1;
			(*tab)[i] -= CELL_LIMIT + 1;
		}
		else
			surplus = 0;
		i--;
	}
}

void	divide_bigint_by_2(bigint *tab)
{
	int				i;
	unsigned int	mod;
	unsigned int	res;
	
	i = 0;
	mod = 0;
	while ((*tab)[i] == 0)
		i++;
	while (i < BIGINT_SIZE)
	{
		res = ((*tab)[i] / 2) + mod;
		mod = (*tab)[i] % 2 == 1 ? 500000000 : 0;
		(*tab)[i] = res;
		i++;
	}
}

unsigned int divide_by_10(unsigned int nb, int power)
{
	int i;
	
	i = 0;
	if (power > 0)
	{
		while (i < power)
		{
			nb /= 10;
			i++;
		}
	}
	return (nb);
}

void    add_bigints(bigint *result, bigint *to_add)
{
	unsigned int surplus;
	int i;
	
	i = BIGINT_SIZE - 1;
	surplus = 0;
	while (i >= 0)
	{
		(*result)[i] += (*to_add)[i];
		(*result)[i] += surplus/(CELL_LIMIT + 1);
		if ((*result)[i] > CELL_LIMIT)
		{
			surplus = CELL_LIMIT + 1;
			(*result)[i] -= CELL_LIMIT + 1;
		}
		else
			surplus = 0;
		i--;
	}
}
