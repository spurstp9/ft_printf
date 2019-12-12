#include "../includes/ft_printf.h"

int		is_flag(char c)
{
	if (c == '#' || c == '+' || c == '-' || c == ' ' || c == '0')
		return (1);
	return (0);
}

int		is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '%')
		return (1);
	return (0);
}

int		is_size(char c)
{
	if (c == 'h' || c == 'j' || c == 'l' || c == 'L' || c == 't' || c == 'z')
		return (1);
	return (0);
}

void 	get_size(char **str, t_conv *c)
{
	int count;
	int size;
	
	while (**str && is_size(**str))
	{
		count = (**str == *(*str + 1)) ? 2 : 1;
		size = compute_size(str, count);
		c->size = ft_max(c->size, size);
	}
}

int 	compute_size(char **str, int count)
{
	int result;

	result = 0;
	if (**str == 'h' && count == 1)
		result = SIZE_H;
	else if (**str == 'h' && count == 2)
		result = SIZE_HH;
	else if ((**str == 'l' || **str == 'L') && count == 1)
		result = SIZE_L;
	else if (**str == 'l' && count == 2)
		result = SIZE_LL;
	else if (**str == 'j')
		result = SIZE_J;
	else if (**str == 'z')
		result = SIZE_Z;
	*str += count;
	return (result);
}
