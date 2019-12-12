#include "../includes/ft_printf.h"

int 	ft_printf(char *str, ...)
{
	va_list	arg_ptr;
	t_conv	c;
	int 	count;
	char 	buffer[BUFF_SIZE + 1];

	va_start(arg_ptr, str);
	count = 0;
    ft_bzero(buffer, BUFF_SIZE);
	while (*str)
	{
        init_conv(&c);
		while (*str && *str != '%')
		{
			count += print_char(*str, c, buffer);
			(str)++;
		}
		if (*str == '%')
		{
			str++;
			count += get_conv_info(&str, arg_ptr, &c, buffer);
		}
	}
	ft_putstr(buffer);
	return (count);
}

int 	get_conv_info(char **str, va_list arg_ptr, t_conv *c, char *buffer)
{
	get_flags(c, str);
	get_width(str, c, arg_ptr);
	get_prec(str, c, arg_ptr);
	get_size(str, c);
	return (get_type(str, buffer, c, arg_ptr));
}
