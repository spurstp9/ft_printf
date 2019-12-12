#include "../includes/ft_printf.h"

void 	convert_unumber(unsigned long long *nb, int size, t_conv c)
{
	if (c.type != 'p')
	{
		if (size == 0)
			*nb = (unsigned int)(*nb);
		else if (size == SIZE_H)
			*nb = (unsigned short)(*nb);
		else if (size == SIZE_HH)
			*nb = (unsigned char)(*nb);
		else if (size == SIZE_L)
			*nb = (unsigned long)(*nb);
	}
}

void 	convert_snumber(long long *nb, int size)
{
	if (size == 0)
		*nb = (int)(*nb);
	else if (size == SIZE_H)
		*nb = (short)(*nb);
	else if (size == SIZE_HH)
		*nb = (char)(*nb);
	else if (size == SIZE_L)
		*nb = (long)(*nb);
}

int 	print_snumber(long long nb, t_conv c, char *buffer)
{
	char	*str;
	int		result;
	int		prefix_len;

	convert_snumber(&nb, c.size);
	result = 0;
	prefix_len = S_INT_PREFIX;
	if (!(str = unb_to_str(ABS(nb), c)))
		return (0);
	if (c.align == 'r' && !c.fill)
		result += put_spaces(c.width - ft_max(ft_strlen(str), c.prec)
			- prefix_len, buffer);
	result += write_sprefix(nb, c, buffer);
	if (c.prec > -1 || c.fill == '0')
	{
		if (c.prec > -1)
			result += put_zeros(c.prec - ft_strlen(str), buffer);
		else
			result += put_zeros(c.width - ft_strlen(str) - prefix_len, buffer);
	}
	result += fill_buffer(buffer, str, ft_strlen(str));
	if (c.align == 'l')
		result += put_spaces(c.width - ft_max(ft_strlen(str), c.prec) - prefix_len, buffer);
	free(str);
	return (result);
}

int 	print_unumber(unsigned long long nb, t_conv c, char *buffer)
{
	char	*str;
	int		result;
	int		prefix_len;

	result = 0;
	convert_unumber(&nb, c.size, c);
	if (!(str = unb_to_str(nb, c)))
		return (0);
	prefix_len = get_uprefix_len(nb, c);
	if (c.align == 'r' && !c.fill)
		result += put_spaces(c.width - ft_max(ft_strlen(str), c.prec) - prefix_len, buffer);
	result += write_uprefix(nb, c, buffer);
	if (c.prec > -1 || c.fill == '0')
	{
		if (c.fill == '0')
			result += put_zeros(c.width - ft_strlen(str) - prefix_len, buffer);
		else
			result += put_zeros(c.prec - ft_strlen(str) - OCT_PREFIX, buffer);
	}
	result += fill_buffer(buffer, str, ft_strlen(str));
	if (c.align == 'l')
		result += put_spaces(c.width - ft_max(ft_strlen(str), c.prec) - prefix_len,
			buffer);
	free(str);
	return (result);
}
