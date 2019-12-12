/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:48:42 by agardina          #+#    #+#             */
/*   Updated: 2019/04/11 20:17:46 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;

	if ((s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
