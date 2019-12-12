# include "../includes/ft_printf.h"

void	init_conv(t_conv *c)
{
	c->align = 'r';
	c->sign = '\0';
	c->fill = '\0';
	c->space = '\0';
	c->hashtag = '\0';
	c->width = -1;
	c->prec = -1;
	c->size = 0;
	c->type = '\0';
}

void	get_flags(t_conv *c, char **str)
{
	while (**str && is_flag(**str))
	{
		if (**str == '-')
		{
			c->align = 'l';
			if (c->fill == '0')
				c->fill = '\0';
		}
		if (**str == '+')
		{
			c->sign = '+';
			if (c->space == ' ')
				c->space = '\0';
		}
		if (**str == '0' && c->align == 'r')
			c->fill = '0';
		if (**str == ' ' && c->sign != '+')
			c->space = ' ';
		if (**str == '#')
			c->hashtag = '#';
		(*str)++;
	}
}

void 	get_width(char **str, t_conv *c, va_list arg_ptr)
{
	int result;

	result = 0;
	if (**str && (ft_isdigit(**str) || **str == '*'))
	{
		if (**str == '*')
		{
			c->width = va_arg(arg_ptr, int);
			(str)++;
		}
		else
		{
			while (**str && ft_isdigit(**str))
			{
				result = (result * 10) + (**str - '0');
				(*str)++;
			}
			c->width = result;
		}
	}
}

/**
* Lorsque la précision et le flag '0' sont utilisés, alors la précision
* est prioritaire sur le flag : elle seule détermine le nombre éventuel
* de 0 à ajouter.
**/

void 	get_prec(char **str, t_conv *c, va_list arg_ptr)
{
	int result;

	
	result = 0;
	if (**str && **str == '.')
	{
		c->prec = 0;
		c->fill = 0;
		(*str)++;
		if (**str && **str == '*')
		{
			c->prec = va_arg(arg_ptr, int);
			(*str)++;
		}
		else if (**str && ft_isdigit(**str))
		{
			while (**str && ft_isdigit(**str))
			{
				result = (result * 10) + (**str - '0');
				(*str)++;
			}
			c->prec = result;
		}
	}
}

int 	get_type(char **str, char *buffer, t_conv *c, va_list arg_ptr)
{
	int count;

	count = 0;
	if (**str)
	{
		c->type = **str;
		if (c->type == '\0')
			return (0);
		else if (c->type == 's')
			count = print_string(va_arg(arg_ptr, char *), *c, buffer);
		else if (c->type == 'd' || c->type == 'i')
			count = print_snumber(va_arg(arg_ptr, long long), *c, buffer);
		else if (c->type == 'u' || c->type == 'o' || c->type == 'x'
			|| c->type == 'X' || c->type == 'p')
			count = print_unumber(va_arg(arg_ptr, unsigned long long), *c, buffer);
		else if (c->type == 'f' && c->size == SIZE_L)
			count = print_long_double(va_arg(arg_ptr, long double), *c, buffer);
		else if (c->type == 'f')
			count = print_double(va_arg(arg_ptr, double), *c, buffer);
		else
			count = print_char(c->type == 'c' ? va_arg(arg_ptr, int) : c->type,
				*c, buffer);
		(*str)++;
	}
	else
        return (0);
	return (count);
}
