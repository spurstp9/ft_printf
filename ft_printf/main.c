#include <stdio.h>
#include "includes/ft_printf.h"
#define TEST_PRINT_STR "%10%\n", 12

int	main(int argc, char **argv)
{
	int a;
	int b;
 
	a = printf("%f", 1.0);
	printf("\nValeur de retour de printf : %d\n", a);
	b = ft_printf("%f", 1.0);
	printf("\nValeur de retour de ft_printf : %d\n", b);
	return (0);
}
