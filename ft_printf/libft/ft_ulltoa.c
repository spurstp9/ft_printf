/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:47:31 by agardina          #+#    #+#             */
/*   Updated: 2019/04/16 18:04:17 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int 	get_len(unsigned long long n)
{
	unsigned int result;

	result = 1;
	while (n / 10)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

static void 			fill_str(unsigned long long n, char *str, int index)
{
	if (n > 9)
		fill_str(n / 10, str, index - 1);
	str[index] = (n % 10) + '0';
}

char 					*ft_ulltoa(unsigned long long n)
{
	int		len;
	char	*str;

	len = get_len(n);
	if ((str = (char*)malloc(sizeof(char) * (size_t)(len + 1))) == NULL)
		return (NULL);
	fill_str(n, str, len - 1);
	str[len] = '\0';
	return (str);
}
