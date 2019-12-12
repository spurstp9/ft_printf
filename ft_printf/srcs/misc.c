#include "../includes/ft_printf.h"

int		fill_buffer(char *buffer, char *str, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i])
		i++;
	while (j < len && (i + j) < BUFF_SIZE)
	{
		buffer[i + j] = str[j];
		j++;
	}
	if (i + j == BUFF_SIZE)
		empty_buffer(buffer);
	if (j < len)
		fill_buffer(buffer, str + j, len - j);
	return (ft_strlen(str));
}

int 	print_string(char *str, t_conv c, char *buffer)
{
	int len;
	
	if (!str)
		return (print_string("(null)", c, buffer));
	len = c.prec > - 1 ? ft_min(ft_strlen(str), c.prec) : ft_strlen(str);
	if (c.align == 'r')
	{
		if (!c.fill)
			put_spaces(c.width - len, buffer);
		else
			put_zeros(c.width - len, buffer);
	}
	fill_buffer(buffer, str, len);
	if (c.align == 'l')
		put_spaces(c.width - len, buffer);
	return (c.width - len > 0 ? c.width : len);
}

int 	print_char(char l, t_conv c, char *buffer)
{
	int result;

	result = 0;
	if (c.align == 'r')
	{
		if (!c.fill)
			result += put_spaces(c.width - 1, buffer);
		else
			result += put_zeros(c.width - 1, buffer);
	}
	if (l == '\0')
	{
		empty_buffer(buffer);
		write(1, &l, 1);
	}
	else
		fill_buffer(buffer, &l, 1);
	result += 1;
	if (c.align == 'l')
		result += put_spaces(c.width - 1, buffer);
	return (result);
}

int 	get_uint_len(unsigned long long nb)
{
	int 			res;

	res = 1;
	while (nb / 10)
	{
		nb /= 10;
		res++;
	}
	return (res);
}

/*
** Imprimer le 0 devant le nombre octal, le 0x ou 0X devant le nombre
** hexadécimal
*/
int		write_uprefix(unsigned long long nb, t_conv c, char *buffer)
{
	if (nb == 0 && (c.type == 'x' || c.type == 'X'))
		return (0);
	if (nb == 0 && c.type == 'o' && c.hashtag == '#' && c.prec == -1)
		return (0);
	else if (c.type == 'o' && c.hashtag == '#')
		return (fill_buffer(buffer, "0", 1));
	else if (((c.type == 'x' && c.hashtag == '#') || c.type == 'p'))
		return (fill_buffer(buffer, "0x", 2));
	else if (c.type == 'X' && c.hashtag == '#')
		return (fill_buffer(buffer, "0X", 2));
	return (0);
}

int		get_uprefix_len(unsigned long long nb, t_conv c)
{
	if (nb == 0 && (c.type == 'x' || c.type == 'X'))
		return (0);
	if (nb == 0 && c.type == 'o' && c.hashtag == '#' && c.prec == -1)
		return (0);
	else if (c.type == 'o' && c.hashtag == '#')
		return (1);
	else if (((c.type == 'x' && c.hashtag == '#') || c.type == 'p'))
		return (2);
	else if (c.type == 'X' && c.hashtag == '#')
		return (2);
	return (0);
}

/*
** Imprimer le -, le + ou l'espace devant l'entier
*/
int		write_sprefix(long long nb, t_conv c, char *buffer)
{
	if (nb >= 0 && c.sign == '+')
		return (fill_buffer(buffer, "+", 1));
	else if (nb >= 0 && c.space == ' ')
		return (fill_buffer(buffer, " ", 1));
	else if (nb < 0)
		return (fill_buffer(buffer, "-", 1));
	return (0);
}

int		put_spaces(int nb, char *buffer)
{
    int count;
    
    count = nb;
	if (count > 0)
	{
		while (count--)
			fill_buffer(buffer, " ", 1);
	}
	return (nb > 0 ? nb : 0);
}

int		put_zeros(int nb, char *buffer)
{
    int count;

    count = nb;
	if (count > 0)
	{
		while (count--)
			fill_buffer(buffer, "0", 1);
	}
	return (nb > 0 ? nb : 0);
}

char 	*unb_to_str(unsigned long long nb, t_conv c)
{
	char *str;

	str = NULL;
	if (nb == 0 && c.prec == 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		str[0] = '\0';
	}
	else
	{
		if (c.type == 'x' || c.type == 'p')
			str = ft_ulltoa_base_str(nb, "0123456789abcdef");
		else if (c.type == 'X')
			str = ft_ulltoa_base_str(nb, "0123456789ABCDEF");
		else if (c.type == 'o')
			str = ft_ulltoa_base_str(nb, "01234567");
		else
			str = ft_ulltoa(nb);
	}
	if (!str)
		return (NULL);
	return (str);
}

void	empty_buffer(char *buffer)
{
	ft_putstr(buffer);
	ft_strclr(buffer);
}
