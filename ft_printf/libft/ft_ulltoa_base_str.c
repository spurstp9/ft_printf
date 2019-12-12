/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:24:24 by agardina          #+#    #+#             */
/*   Updated: 2019/04/25 21:36:18 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int 		err_base(char *base)
{
	int i;
	int j;

	if (!base || ft_strlen(base) < 2 || ft_strlen(base) > 16)
		return (1);
	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == '-' || base[j] == '+')
				return (1);
			if (base[j] == base[i] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int 		get_str_len(unsigned long long nbr, char *base)
{
	int 					count;
	unsigned int 			len_base;

	len_base = (unsigned int)ft_strlen(base);
	count = 1;
	while (nbr > len_base - 1)
	{
		count++;
		nbr = nbr / len_base;
	}
	return (count);
}

static void 	convert_nbr(unsigned long long nbr, char *base, char *str, int index)
{
	unsigned int 			len_base;

	len_base = (unsigned int)ft_strlen(base);
	if (nbr > len_base - 1)
		convert_nbr((long long)(nbr / len_base), base, str, index - 1);
	str[index] = base[nbr % len_base];
}

char 			*ft_ulltoa_base_str(unsigned long long nbr, char *base)
{
	int		str_len;
	char	*str;

	if (!err_base(base))
	{
		str_len = get_str_len(nbr, base);
		if ((str = (char*)malloc(sizeof(char) * ((size_t)str_len + 1))) != NULL)
		{
			convert_nbr(nbr, base, str, str_len - 1);
			str[str_len] = '\0';
			return (str);
		}
	}
	return (NULL);
}
