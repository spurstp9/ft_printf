/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:23:28 by agardina          #+#    #+#             */
/*   Updated: 2019/12/12 14:22:22 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/prototypes.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int	main(void)
{
	int a;
	int b;

	a = ft_printf("%.8Lf", -875.000000009000000l);
	printf("\n");
	b = printf("%.8Lf", -875.000000009000000l);
	printf("\n");
	return (0);
}
