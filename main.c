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
	ft_printf("%Lf\n", -100.25L / 0.0L);
	printf("%Lf\n", -100.25L / 0.0L);
	return (0);
}
