#include "../../includes/ft_printf.h"

void    init_bigint(bigint *tab)
{
    int i;
    
    i = 0;
    while (i < BIGINT_SIZE)
    {
        (*tab)[i] = 0;
        i++;
    }
}

void    create_unit(bigint *tab, unsigned int size, int expo)
{
    int i;
    
    i = 0;
	if ((size == 8 && expo >= 0) || (size == 16 && expo >= 0))
	{
		while (i < BIGINT_SIZE - 5)
		{
			(*tab)[i] = 0;
			i++;
		}
		(*tab)[BIGINT_SIZE - 1] = size == 8 ? 500000000 : 142578125;
		(*tab)[BIGINT_SIZE - 2] = size == 8 ? 618164062 : 86994171;
		(*tab)[BIGINT_SIZE - 3] = size == 8 ? 84726333 : 400745280;
		(*tab)[BIGINT_SIZE - 4] = size == 8 ? 925031308 : 248550443;
		(*tab)[BIGINT_SIZE - 5] = size == 8 ? 222044604 : 108420217;
	}
	else
	{
		(*tab)[0] = 0;
		i = 0;
		(*tab)[i + 1] = 500000000;
		while  (++i < BIGINT_SIZE)
			(*tab)[i + 1] = 0;
	}
}

void	filling_zeros(unsigned int nb)
{
	if (nb < 100000000)
		write(1, "0", 1);
	if (nb < 10000000)
		write(1, "0", 1);
	if (nb < 1000000)
		write(1, "0", 1);
	if (nb < 100000)
		write(1, "0", 1);
	if (nb < 10000)
		write(1, "0", 1);
	if (nb < 1000)
		write(1, "0", 1);
	if (nb < 100)
		write(1, "0", 1);
	if (nb < 10)
		write(1, "0", 1);
	if (nb < 1)
		write(1, "0", 1);
}

int	only_nine(unsigned int nb)
{
	if (!nb)
		return (0);
	while (nb)
	{
		if (nb % 10 == 9)
			nb /= 10;
		else
			return (0);
	}
	return (1);
}