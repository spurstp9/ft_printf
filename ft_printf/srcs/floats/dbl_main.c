#include "../../includes/ft_printf.h"

int 	print_long_double(long double f, t_conv c, char *buffer)
{
		return (main_ld(f, c, buffer));
}

int 	print_double(double f, t_conv c, char *buffer)
{
	return (main_d(f, c, buffer));
}

int main_ld(long double f, t_conv conv, char *buffer)
{
	int sign;
	int to_print;
	t_ldbl ldbl;

	ldbl.bits.f = f;
	if ((sign = ldbl.bits.u[4]>>15))
		ldbl.bits.u[4] = ldbl.bits.u[4] ^ 0x8000;
	ldbl.expo = (((ldbl.bits.u[4])<<1)>>1) - 16383;
	to_print = 0;
	if (sign)
	{
		to_print += 1;
		print_char('-', conv, buffer);
	}
	if (conv.prec == -1)
		conv.prec = 6;
	manage_ldbl(&ldbl, conv.prec, &to_print, buffer);
	return (to_print);
}

int main_d(double f, t_conv conv, char *buffer)
{
	int sign;
	int to_print;
	t_dbl dbl;
	
	dbl.bits.f = f;
	if ((sign = dbl.bits.u>>63))
		dbl.bits.u = dbl.bits.u ^ 0x8000000000000000;
	dbl.expo = (((dbl.bits.u)<<1)>>53) - 1023;
	to_print = 0;
	dbl.mant = (dbl.bits.u)<<12;
	if (sign)
	{
		to_print += 1;
		print_char('-', conv, buffer);
	}
	if (conv.prec == -1)
		conv.prec = 6;
	manage_dbl(&dbl, conv.prec, &to_print, buffer);
	return (to_print);
}
