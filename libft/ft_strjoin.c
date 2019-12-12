/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:27:44 by agardina          #+#    #+#             */
/*   Updated: 2019/04/24 13:43:23 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len_s1;
	int		len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	len_s1 = (int)ft_strlen(s1);
	len_s2 = (int)ft_strlen(s2);
	new = (char*)malloc(sizeof(char) * (size_t)(len_s1 + len_s2 + 1));
	if (new == NULL)
		return (NULL);
	ft_memset(new, 0, (size_t)(len_s1 + len_s2 + 1));
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	return (new);
}
