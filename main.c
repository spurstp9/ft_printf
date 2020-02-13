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

void test_d(void);
void test_o(void);
void test_x(void);
void test_big_x(void);
void test_u(void);
void test_p(void);
void test_c(void);
void test_s(void);
void test_f(void);
void test_err(int a, int b);

int	main(void)
{
		test_d();
		test_o();
		test_x();
		test_big_x();
		test_u();
		test_p();
		test_c();
		test_s();
		test_f();
}

void test_err(int a, int b)
{
	if (a == b)
		printf("\n");
	else
		printf("ERREUR DE RETOUR\n");
}

void test_d(void)
{
		int a;
		int b;

		a = printf("---------------Test d--------------\n\n");
		a = printf("%d\n", 0);
		b = ft_printf("%d\n", 0);
		test_err(a, b);

		a = printf("%.0d\n", 0);
		b = ft_printf("%.0d\n", 0);
		test_err(a, b);

		a = printf("%0.0d\n", 0);
		b = ft_printf("%0.0d\n", 0);
		test_err(a, b);

		a = printf("%0d\n", 0);
		b = ft_printf("%0d\n", 0);
		test_err(a, b);

		a = printf("%.10d\n", 0);
		b = ft_printf("%.10d\n", 0);
		test_err(a, b);

		a = printf("%10d\n", 0);
		b = ft_printf("%10d\n", 0);
		test_err(a, b);

		a = printf("%-10d\n", 0);
		b = ft_printf("%-10d\n", 0);
		test_err(a, b);

		a = printf("%d\n", INT_MIN);
		b = ft_printf("%d\n", INT_MIN);
		test_err(a, b);

		a = printf("%d\n", INT_MAX);
		b = ft_printf("%d\n", INT_MAX);
		test_err(a, b);

		a = printf("%d\n", 12345);
		b = ft_printf("%d\n", 12345);
		test_err(a, b);

		a = printf("%-10d\n", 12345);
		b = ft_printf("%-10d\n", 12345);
		test_err(a, b);

		a = printf("%+.20d\n", 12345);
		b = ft_printf("%+.20d\n", 12345);
		test_err(a, b);

		a = printf("% +.20d\n", 12345);
		b = ft_printf("% +.20d\n", 12345);
		test_err(a, b);

		a = printf("% +-.20d\n", 12345);
		b = ft_printf("% +-.20d\n", 12345);
		test_err(a, b);

		a = printf("% +10-.20d\n", 12345);
		b = ft_printf("% +10-.20d\n", 12345);
		test_err(a, b);

		a = printf("% +30-.20d\n", 12345);
		b = ft_printf("% +30-.20d\n", 12345);
		test_err(a, b);

		a = printf("%3.10d\n", 12345);
		b = ft_printf("%3.10d\n", 12345);
		test_err(a, b);

		a = printf("%10.3d\n", 12345);
		b = ft_printf("%10.3d\n", 12345);
		test_err(a, b);

		a = printf("%010.3d\n", 12345);
		b = ft_printf("%010.3d\n", 12345);
		test_err(a, b);

		a = printf("%-010.3d\n", 12345);
		b = ft_printf("%-010.3d\n", 12345);
		test_err(a, b);

		a = printf("%+010.3d\n", 12345);
		b = ft_printf("%+010.3d\n", 12345);
		test_err(a, b);

		a = printf("%d\n", -12345);
		b = ft_printf("%d\n", -12345);
		test_err(a, b);

		a = printf("%-10d\n", -12345);
		b = ft_printf("%-10d\n", -12345);
		test_err(a, b);

		a = printf("%+.20d\n", -12345);
		b = ft_printf("%+.20d\n", -12345);
		test_err(a, b);

		a = printf("% +.20d\n", -12345);
		b = ft_printf("% +.20d\n", -12345);
		test_err(a, b);

		a = printf("% +-.20d\n", -12345);
		b = ft_printf("% +-.20d\n", -12345);
		test_err(a, b);

		a = printf("% +10-.20d\n", -12345);
		b = ft_printf("% +10-.20d\n", -12345);
		test_err(a, b);

		a = printf("% +30-.20d\n", -12345);
		b = ft_printf("% +30-.20d\n", -12345);
		test_err(a, b);

		a = printf("%3.10d\n", -12345);
		b = ft_printf("%3.10d\n", -12345);
		test_err(a, b);

		a = printf("%10.3d\n", -12345);
		b = ft_printf("%10.3d\n", -12345);
		test_err(a, b);

		a = printf("%010.3d\n", -12345);
		b = ft_printf("%010.3d\n", -12345);
		test_err(a, b);

		a = printf("%-010.3d\n", -12345);
		b = ft_printf("%-010.3d\n", -12345);
		test_err(a, b);

		a = printf("%+010.3d\n", -12345);
		b = ft_printf("%+010.3d\n", -12345);
		test_err(a, b);
}

void test_o(void)
{
		int a;
		int b;

		a = printf("---------------Test o--------------\n\n");
		a = printf("%o\n", 0);
		b = ft_printf("%o\n", 0);
		test_err(a, b);

		a = printf("%.0o\n", 0);
		b = ft_printf("%.0o\n", 0);
		test_err(a, b);

		a = printf("%0.0o\n", 0);
		b = ft_printf("%0.0o\n", 0);
		test_err(a, b);

		a = printf("%0o\n", 0);
		b = ft_printf("%0o\n", 0);
		test_err(a, b);

		a = printf("%#o\n", 0);
		b = ft_printf("%#o\n", 0);
		test_err(a, b);

		a = printf("%#0o\n", 0);
		b = ft_printf("%#0o\n", 0);
		test_err(a, b);

		a = printf("%0o\n", 0);
		b = ft_printf("%0o\n", 0);
		test_err(a, b);

		a = printf("%o\n", INT_MIN);
		b = ft_printf("%o\n", INT_MIN);
		test_err(a, b);

		a = printf("%o\n", INT_MAX);
		b = ft_printf("%o\n", INT_MAX);
		test_err(a, b);

		a = printf("%#o\n", 12345);
		b = ft_printf("%#o\n", 12345);
		test_err(a, b);

		a = printf("%-10o\n", 12345);
		b = ft_printf("%-10o\n", 12345);
		test_err(a, b);

		a = printf("%+010o\n", 12345);
		b = ft_printf("%+010o\n", 12345);
		test_err(a, b);

		a = printf("%+.20o\n", 12345);
		b = ft_printf("%+.20o\n", 12345);
		test_err(a, b);

		a = printf("%10.20o\n", 12345);
		b = ft_printf("%10.20o\n", 12345);
		test_err(a, b);

		a = printf("%30.20o\n", 12345);
		b = ft_printf("%30.20o\n", 12345);
		test_err(a, b);

		a = printf("%#30.20o\n", 12345);
		b = ft_printf("%#30.20o\n", 12345);
		test_err(a, b);

		a = printf("%#30.20o\n", INT_MAX);
		b = ft_printf("%#30.20o\n", INT_MAX);
		test_err(a, b);

		a = printf("%#30.20o\n", INT_MIN);
		b = ft_printf("%#30.20o\n", INT_MIN);
		test_err(a, b);

		a = printf("%+010o\n", INT_MAX);
		b = ft_printf("%+010o\n", INT_MAX);
		test_err(a, b);

		a = printf("%+.20o\n", INT_MAX);
		b = ft_printf("%+.20o\n", INT_MAX);
		test_err(a, b);

		a = printf("%10.20o\n", INT_MAX);
		b = ft_printf("%10.20o\n", INT_MAX);
		test_err(a, b);

		a = printf("%+010o\n", INT_MIN);
		b = ft_printf("%+010o\n", INT_MIN);
		test_err(a, b);

		a = printf("%+.20o\n", INT_MIN);
		b = ft_printf("%+.20o\n", INT_MIN);
		test_err(a, b);

		a = printf("%10.20o\n", INT_MIN);
		b = ft_printf("%10.20o\n", INT_MIN);
		test_err(a, b);

		a = printf("%10.*o\n",30, INT_MIN);
		b = ft_printf("%10.*o\n",30, INT_MIN);
		test_err(a, b);

		a = printf("%10.*o\n", 5, INT_MIN);
		b = ft_printf("%10.*o\n", 5, INT_MIN);
		test_err(a, b);

		a = printf("%10.*o\n", -5, INT_MIN);
		b = ft_printf("%10.*o\n", -5, INT_MIN);
		test_err(a, b);

		a = printf("%#o\n", -12345);
		b = ft_printf("%#o\n", -12345);
		test_err(a, b);

		a = printf("%-10o\n", -12345);
		b = ft_printf("%-10o\n", -12345);
		test_err(a, b);

		a = printf("%+010o\n", -12345);
		b = ft_printf("%+010o\n", -12345);
		test_err(a, b);

		a = printf("%+.20o\n", -12345);
		b = ft_printf("%+.20o\n", -12345);
		test_err(a, b);

		a = printf("%10.20o\n", -12345);
		b = ft_printf("%10.20o\n", -12345);
		test_err(a, b);

		a = printf("%30.20o\n", -12345);
		b = ft_printf("%30.20o\n", -12345);
		test_err(a, b);

		a = printf("%#30.20o\n", -12345);
		b = ft_printf("%#30.20o\n", -12345);
		test_err(a, b);
}

void test_x(void)
{
		int a;
		int b;

		a = printf("---------------Test x--------------\n\n");
		a = printf("%x\n", 0);
		b = ft_printf("%x\n", 0);
		test_err(a, b);

		a = printf("%.0x\n", 0);
		b = ft_printf("%.0x\n", 0);
		test_err(a, b);

		a = printf("%0.0x\n", 0);
		b = ft_printf("%0.0x\n", 0);
		test_err(a, b);

		a = printf("%0x\n", 0);
		b = ft_printf("%0x\n", 0);
		test_err(a, b);

		a = printf("%#x\n", 0);
		b = ft_printf("%#x\n", 0);
		test_err(a, b);

		a = printf("%#0x\n", 0);
		b = ft_printf("%#0x\n", 0);
		test_err(a, b);

		a = printf("%0x\n", 0);
		b = ft_printf("%0x\n", 0);
		test_err(a, b);

		a = printf("%x\n", INT_MIN);
		b = ft_printf("%x\n", INT_MIN);
		test_err(a, b);

		a = printf("%x\n", INT_MAX);
		b = ft_printf("%x\n", INT_MAX);
		test_err(a, b);

		a = printf("%#x\n", 12345);
		b = ft_printf("%#x\n", 12345);
		test_err(a, b);

		a = printf("%-10x\n", 12345);
		b = ft_printf("%-10x\n", 12345);
		test_err(a, b);

		a = printf("%+010x\n", 12345);
		b = ft_printf("%+010x\n", 12345);
		test_err(a, b);

		a = printf("%+.20x\n", 12345);
		b = ft_printf("%+.20x\n", 12345);
		test_err(a, b);

		a = printf("%10.20x\n", 12345);
		b = ft_printf("%10.20x\n", 12345);
		test_err(a, b);

		a = printf("%30.20x\n", 12345);
		b = ft_printf("%30.20x\n", 12345);
		test_err(a, b);

		a = printf("%#30.20x\n", 12345);
		b = ft_printf("%#30.20x\n", 12345);
		test_err(a, b);

		a = printf("%#30.20x\n", INT_MAX);
		b = ft_printf("%#30.20x\n", INT_MAX);
		test_err(a, b);

		a = printf("%#30.20x\n", INT_MIN);
		b = ft_printf("%#30.20x\n", INT_MIN);
		test_err(a, b);

		a = printf("%+010x\n", INT_MAX);
		b = ft_printf("%+010x\n", INT_MAX);
		test_err(a, b);

		a = printf("%+.20x\n", INT_MAX);
		b = ft_printf("%+.20x\n", INT_MAX);
		test_err(a, b);

		a = printf("%10.20x\n", INT_MAX);
		b = ft_printf("%10.20x\n", INT_MAX);
		test_err(a, b);

		a = printf("%+010x\n", INT_MIN);
		b = ft_printf("%+010x\n", INT_MIN);
		test_err(a, b);

		a = printf("%+.20x\n", INT_MIN);
		b = ft_printf("%+.20x\n", INT_MIN);
		test_err(a, b);

		a = printf("%10.20x\n", INT_MIN);
		b = ft_printf("%10.20x\n", INT_MIN);
		test_err(a, b);

		a = printf("%10.*x\n", 30, INT_MIN);
		b = ft_printf("%10.*x\n", 30, INT_MIN);
		test_err(a, b);

		a = printf("%10.*x\n", 5, INT_MIN);
		b = ft_printf("%10.*x\n", 5, INT_MIN);
		test_err(a, b);

		a = printf("%10.*x\n", -5, INT_MIN);
		b = ft_printf("%10.*x\n", -5, INT_MIN);
		test_err(a, b);


}

void test_big_x(void)
{
		int a;
		int b;

		a = printf("---------------Test X--------------\n\n");
		a = printf("%X\n", 0);
		b = ft_printf("%X\n", 0);
		test_err(a, b);

		a = printf("%.0X\n", 0);
		b = ft_printf("%.0X\n", 0);
		test_err(a, b);

		a = printf("%0.0X\n", 0);
		b = ft_printf("%0.0X\n", 0);
		test_err(a, b);

		a = printf("%0X\n", 0);
		b = ft_printf("%0X\n", 0);
		test_err(a, b);

		a = printf("%#X\n", 0);
		b = ft_printf("%#X\n", 0);
		test_err(a, b);

		a = printf("%#0X\n", 0);
		b = ft_printf("%#0X\n", 0);
		test_err(a, b);

		a = printf("%0X\n", 0);
		b = ft_printf("%0X\n", 0);
		test_err(a, b);

		a = printf("%X\n", INT_MIN);
		b = ft_printf("%X\n", INT_MIN);
		test_err(a, b);

		a = printf("%X\n", INT_MAX);
		b = ft_printf("%X\n", INT_MAX);
		test_err(a, b);

		a = printf("%#X\n", 12345);
		b = ft_printf("%#X\n", 12345);
		test_err(a, b);

		a = printf("%-10X\n", 12345);
		b = ft_printf("%-10X\n", 12345);
		test_err(a, b);

		a = printf("%+010X\n", 12345);
		b = ft_printf("%+010X\n", 12345);
		test_err(a, b);

		a = printf("%+.20X\n", 12345);
		b = ft_printf("%+.20X\n", 12345);
		test_err(a, b);

		a = printf("%10.20X\n", 12345);
		b = ft_printf("%10.20X\n", 12345);
		test_err(a, b);

		a = printf("%30.20X\n", 12345);
		b = ft_printf("%30.20X\n", 12345);
		test_err(a, b);

		a = printf("%#30.20X\n", 12345);
		b = ft_printf("%#30.20X\n", 12345);
		test_err(a, b);

		a = printf("%#30.20X\n", INT_MAX);
		b = ft_printf("%#30.20X\n", INT_MAX);
		test_err(a, b);

		a = printf("%#30.20X\n", INT_MIN);
		b = ft_printf("%#30.20X\n", INT_MIN);
		test_err(a, b);

		a = printf("%+010X\n", INT_MAX);
		b = ft_printf("%+010X\n", INT_MAX);
		test_err(a, b);

		a = printf("%+.20X\n", INT_MAX);
		b = ft_printf("%+.20X\n", INT_MAX);
		test_err(a, b);

		a = printf("%10.20X\n", INT_MAX);
		b = ft_printf("%10.20X\n", INT_MAX);
		test_err(a, b);

		a = printf("%+010X\n", INT_MIN);
		b = ft_printf("%+010X\n", INT_MIN);
		test_err(a, b);

		a = printf("%+.20X\n", INT_MIN);
		b = ft_printf("%+.20X\n", INT_MIN);
		test_err(a, b);

		a = printf("%10.20X\n", INT_MIN);
		b = ft_printf("%10.20X\n", INT_MIN);
		test_err(a, b);

		a = printf("%10.*X\n", 30, INT_MIN);
		b = ft_printf("%10.*X\n", 30, INT_MIN);
		test_err(a, b);

		a = printf("%10.*X\n", 5, INT_MIN);
		b = ft_printf("%10.*X\n", 5, INT_MIN);
		test_err(a, b);

		a = printf("%10.*X\n", -5, INT_MIN);
		b = ft_printf("%10.*X\n", -5, INT_MIN);
		test_err(a, b);

		a = printf("%#X\n", -12345);
		b = ft_printf("%#X\n", -12345);
		test_err(a, b);

		a = printf("%-10X\n", -12345);
		b = ft_printf("%-10X\n", -12345);
		test_err(a, b);

		a = printf("%+010X\n", -12345);
		b = ft_printf("%+010X\n", -12345);
		test_err(a, b);

		a = printf("%+.20X\n", -12345);
		b = ft_printf("%+.20X\n", -12345);
		test_err(a, b);

		a = printf("%10.20X\n", -12345);
		b = ft_printf("%10.20X\n", -12345);
		test_err(a, b);

		a = printf("%30.20X\n", -12345);
		b = ft_printf("%30.20X\n", -12345);
		test_err(a, b);

		a = printf("%#30.20X\n", -12345);
		b = ft_printf("%#30.20X\n", -12345);
		test_err(a, b);
}

void test_u(void)
{
		int a;
		int b;

		a = printf("---------------Test u--------------\n\n");
		a = printf("%u\n", 0);
		b = ft_printf("%u\n", 0);
		test_err(a, b);

		a = printf("%.0u\n", 0);
		b = ft_printf("%.0u\n", 0);
		test_err(a, b);

		a = printf("%0.0u\n", 0);
		b = ft_printf("%0.0u\n", 0);
		test_err(a, b);

		a = printf("%0u\n", 0);
		b = ft_printf("%0u\n", 0);
		test_err(a, b);

		a = printf("%#u\n", 0);
		b = ft_printf("%#u\n", 0);
		test_err(a, b);

		a = printf("%#0u\n", 0);
		b = ft_printf("%#0u\n", 0);
		test_err(a, b);

		a = printf("%0u\n", 0);
		b = ft_printf("%0u\n", 0);
		test_err(a, b);

		a = printf("%u\n", INT_MIN);
		b = ft_printf("%u\n", INT_MIN);
		test_err(a, b);

		a = printf("%u\n", INT_MAX);
		b = ft_printf("%u\n", INT_MAX);
		test_err(a, b);

		a = printf("%#u\n", 12345);
		b = ft_printf("%#u\n", 12345);
		test_err(a, b);

		a = printf("%-10u\n", 12345);
		b = ft_printf("%-10u\n", 12345);
		test_err(a, b);

		a = printf("%+010u\n", 12345);
		b = ft_printf("%+010u\n", 12345);
		test_err(a, b);

		a = printf("%+.20u\n", 12345);
		b = ft_printf("%+.20u\n", 12345);
		test_err(a, b);

		a = printf("%10.20u\n", 12345);
		b = ft_printf("%10.20u\n", 12345);
		test_err(a, b);

		a = printf("%30.20u\n", 12345);
		b = ft_printf("%30.20u\n", 12345);
		test_err(a, b);

		a = printf("%#30.20u\n", 12345);
		b = ft_printf("%#30.20u\n", 12345);
		test_err(a, b);

		a = printf("%#30.20u\n", INT_MAX);
		b = ft_printf("%#30.20u\n", INT_MAX);
		test_err(a, b);

		a = printf("%#30.20u\n", INT_MIN);
		b = ft_printf("%#30.20u\n", INT_MIN);
		test_err(a, b);

		a = printf("%+010u\n", INT_MAX);
		b = ft_printf("%+010u\n", INT_MAX);
		test_err(a, b);

		a = printf("%+.20u\n", INT_MAX);
		b = ft_printf("%+.20u\n", INT_MAX);
		test_err(a, b);

		a = printf("%10.20u\n", INT_MAX);
		b = ft_printf("%10.20u\n", INT_MAX);
		test_err(a, b);

		a = printf("%+010u\n", INT_MIN);
		b = ft_printf("%+010u\n", INT_MIN);
		test_err(a, b);

		a = printf("%+.20u\n", INT_MIN);
		b = ft_printf("%+.20u\n", INT_MIN);
		test_err(a, b);

		a = printf("%10.20u\n", INT_MIN);
		b = ft_printf("%10.20u\n", INT_MIN);
		test_err(a, b);

		a = printf("%10.*u\n", 30, INT_MIN);
		b = ft_printf("%10.*u\n", 30, INT_MIN);
		test_err(a, b);

		a = printf("%10.*u\n", 5, INT_MIN);
		b = ft_printf("%10.*u\n", 5, INT_MIN);
		test_err(a, b);

		a = printf("%10.*u\n", -5, INT_MIN);
		b = ft_printf("%10.*u\n", -5, INT_MIN);
		test_err(a, b);

		a = printf("%#u\n", -12345);
		b = ft_printf("%#u\n", -12345);
		test_err(a, b);

		a = printf("%-10u\n", -12345);
		b = ft_printf("%-10u\n", -12345);
		test_err(a, b);

		a = printf("%+010u\n", -12345);
		b = ft_printf("%+010u\n", -12345);
		test_err(a, b);

		a = printf("%+.20u\n", -12345);
		b = ft_printf("%+.20u\n", -12345);
		test_err(a, b);

		a = printf("%10.20u\n", -12345);
		b = ft_printf("%10.20u\n", -12345);
		test_err(a, b);

		a = printf("%30.20u\n", -12345);
		b = ft_printf("%30.20u\n", -12345);
		test_err(a, b);

		a = printf("%#30.20u\n", -12345);
		b = ft_printf("%#30.20u\n", -12345);
		test_err(a, b);
}

void test_p(void)
{
		char str[] = "Bonjour";
		char *str2 = NULL;
		int a;
		int b;

		a = printf("---------------Test p--------------\n\n");
		a = printf("%p\n", 0);
		b = ft_printf("%p\n", 0);
		test_err(a, b);

		a = printf("%.0p\n", 0);
		b = ft_printf("%.0p\n", 0);
		test_err(a, b);

		a = printf("%0.0p\n", 0);
		b = ft_printf("%0.0p\n", 0);
		test_err(a, b);

		a = printf("%0p\n", 0);
		b = ft_printf("%0p\n", 0);
		test_err(a, b);

		a = printf("%p\n", INT_MIN);
		b = ft_printf("%p\n", INT_MIN);
		test_err(a, b);

		a = printf("%p\n", INT_MAX);
		b = ft_printf("%p\n", INT_MAX);
		test_err(a, b);

		a = printf("%p\n", str);
		b = ft_printf("%p\n", str);
		test_err(a, b);

		a = printf("%#p\n", str);
		b = ft_printf("%#p\n", str);
		test_err(a, b);

		a = printf("%p\n", str2);
		b = ft_printf("%p\n", str2);
		test_err(a, b);

		a = printf("%0p\n", str2);
		b = ft_printf("%0p\n", str2);
		test_err(a, b);

		a = printf("%0.0p\n", str2);
		b = ft_printf("%0.0p\n", str2);
		test_err(a, b);

		a = printf("%.0p\n", str2);
		b = ft_printf("%.0p\n", str2);
		test_err(a, b);

		a = printf("%0100p\n", str2);
		b = ft_printf("%0100p\n", str2);
		test_err(a, b);

		a = printf("%+0100p\n", str2);
		b = ft_printf("%+0100p\n", str2);
		test_err(a, b);

		a = printf("%-+0100p\n", str2);
		b = ft_printf("%-+0100p\n", str2);
		test_err(a, b);

		a = printf("%-0100.40p\n", str2);
		b = ft_printf("%-0100.40p\n", str2);
		test_err(a, b);
}

void test_c(void)
{
		int a;
		int b;
		char str[] = "Bonjour";

		a = printf("---------------Test c--------------\n\n");

		a = printf("%c\n", '\0');
		printf("Ohoh\n");
		b = ft_printf("%c\n", '\0');
		test_err(a, b);

		a = printf("%c\n", 'a');
		b = ft_printf("%c\n", 'a');
		test_err(a, b);

		a = printf("%10c\n", 'a');
		b = ft_printf("%10c\n", 'a');
		test_err(a, b);

		a = printf("%-10c\n", 'a');
		b = ft_printf("%-10c\n", 'a');
		test_err(a, b);

		a = printf("%+10c\n", 'a');
		b = ft_printf("%+10c\n", 'a');
		test_err(a, b);

		a = printf("% 10c\n", 'a');
		b = ft_printf("% 10c\n", 'a');
		test_err(a, b);

		a = printf("% -10c\n", 'a');
		b = ft_printf("% -10c\n", 'a');
		test_err(a, b);

		a = printf("% +10c\n", 'a');
		b = ft_printf("% +10c\n", 'a');
		test_err(a, b);

		a = printf("% +10c\n", 'a');
		b = ft_printf("% +10c\n", 'a');
		test_err(a, b);

		a = printf("%.10c\n", 'a');
		b = ft_printf("%.10c\n", 'a');
		test_err(a, b);

		a = printf("%0.10c\n", 'a');
		b = ft_printf("%0.10c\n", 'a');
		test_err(a, b);

		a = printf("%010c\n", 'a');
		b = ft_printf("%010c\n", 'a');
		test_err(a, b);

		a = printf("%c\n", str);
		b = ft_printf("%c\n", str);
		test_err(a, b);

		a = printf("%c\n", 10);
		b = ft_printf("%c\n", 10);
		test_err(a, b);

		a = printf("%.0c\n", 'a');
		b = ft_printf("%.0c\n", 'a');
		test_err(a, b);
}

void test_s(void)
{
		int a;
		int b;

		char str[] = "abc";
		char str2[] = "Lorem ipsum dolor sit amet.";
		char *str3 = NULL;
		a = printf("---------------Test s--------------\n\n");

		a = printf("%s\n", str);
		b = ft_printf("%s\n", str);
		test_err(a, b);

		a = printf("%10s\n", str);
		b = ft_printf("%10s\n", str);
		test_err(a, b);

		a = printf("%-10s\n", str);
		b = ft_printf("%-10s\n", str);
		test_err(a, b);

		a = printf("%+10s\n", str);
		b = ft_printf("%+10s\n", str);
		test_err(a, b);

		a = printf("% 10s\n", str);
		b = ft_printf("% 10s\n", str);
		test_err(a, b);

		a = printf("%.10s\n", str);
		b = ft_printf("%.10s\n", str);
		test_err(a, b);

		a = printf("%.10s\n", str);
		b = ft_printf("%.10s\n", str);
		test_err(a, b);

		a = printf("%s\n", str2);
		b = ft_printf("%s\n", str2);
		test_err(a, b);

		a = printf("%10s\n", str2);
		b = ft_printf("%10s\n", str2);
		test_err(a, b);

		a = printf("%-10s\n", str2);
		b = ft_printf("%-10s\n", str2);
		test_err(a, b);

		a = printf("%+10s\n", str2);
		b = ft_printf("%+10s\n", str2);
		test_err(a, b);

		a = printf("% 10s\n", str2);
		b = ft_printf("% 10s\n", str2);
		test_err(a, b);

		a = printf("%.10s\n", str2);
		b = ft_printf("%.10s\n", str2);
		test_err(a, b);

		a = printf("%.10s\n", str2);
		b = ft_printf("%.10s\n", str2);
		test_err(a, b);

		a = printf("%s\n", str3);
		b = ft_printf("%s\n", str3);

		a = printf("%10s\n", str3);
		b = ft_printf("%10s\n", str3);
		test_err(a, b);

		a = printf("%010s\n", str3);
		b = ft_printf("%010s\n", str3);
		test_err(a, b);

		a = printf("%-010s\n", str3);
		b = ft_printf("%-010s\n", str3);
		test_err(a, b);

		a = printf("%- 010s\n", str3);
		b = ft_printf("%- 010s\n", str3);
		test_err(a, b);

		a = printf("% 010s\n", str3);
		b = ft_printf("% 010s\n", str3);
		test_err(a, b);

		a = printf("%.10s\n", str3);
		b = ft_printf("%.10s\n", str3);
		test_err(a, b);

		a = printf("%.2s\n", str3);
		b = ft_printf("%.2s\n", str3);
		test_err(a, b);

		a = printf("%.*s\n", str3, 2);
		b = ft_printf("%.*s\n", str3, 2);
		test_err(a, b);

		a = printf("%.*s\n", str3, 10);
		b = ft_printf("%.*s\n", str3, 10);
		test_err(a, b);
}

void test_f(void)
{
		int a;
		int b;

		a = printf("---------------Test f--------------\n\n");

		a = printf("%f\n", DBL_MIN);
		b = ft_printf("%f\n", DBL_MIN);
		test_err(a, b);

		a = printf("%f\n", DBL_MAX);
		b = ft_printf("%f\n", DBL_MAX);
		test_err(a, b);

		a = printf("%Lf\n", LDBL_MIN);
		b = ft_printf("%Lf\n", LDBL_MIN);
		test_err(a, b);

		a = printf("%Lf\n", LDBL_MAX);
		b = ft_printf("%Lf\n", LDBL_MAX);
		test_err(a, b);

		a = printf("%Lf\n", 10.0L / 0.0L);
		b = ft_printf("%Lf\n", 10.0L / 0.0L);
		test_err(a, b);

		a = printf("%Lf\n", -10.0L / 0.0L);
		b = ft_printf("%Lf\n", -10.0L / 0.0L);
		test_err(a, b);

		a = printf("%Lf\n", 0.0L / 0.0L);
		b = ft_printf("%Lf\n", 0.0L / 0.0L);
		test_err(a, b);

		a = printf("%Lf\n", -0.0L / 0.0L);
		b = ft_printf("%Lf\n", -0.0L / 0.0L);
		test_err(a, b);

		a = printf("%f\n", 10.0 / 0.0);
		b = ft_printf("%f\n", 10.0 / 0.0);
		test_err(a, b);

		a = printf("%f\n", -10.0 / 0.0);
		b = ft_printf("%f\n", -10.0 / 0.0);
		test_err(a, b);

		a = printf("%f\n", 0.0 / 0.0);
		b = ft_printf("%f\n", 0.0 / 0.0);
		test_err(a, b);

		a = printf("%f\n", -0.0 / 0.0);
		b = ft_printf("%f\n", -0.0 / 0.0);
		test_err(a, b);

		a = printf("%.20f\n", 123.456);
		b = ft_printf("%.20f\n", 123.456);
		test_err(a, b);

		a = printf("%30.20f\n", 123.456);
		b = ft_printf("%30.20f\n", 123.456);
		test_err(a, b);

		a = printf("%030.20f\n", 123.456);
		b = ft_printf("%030.20f\n", 123.456);
		test_err(a, b);

		a = printf("% 030.20f\n", 123.456);
		b = ft_printf("% 030.20f\n", 123.456);
		test_err(a, b);

		a = printf("% 30.20f\n", 123.456);
		b = ft_printf("% 30.20f\n", 123.456);
		test_err(a, b);

		a = printf("%-30.20f\n", 123.456);
		b = ft_printf("%-30.20f\n", 123.456);
		test_err(a, b);

		a = printf("%10.20f\n", 123.456);
		b = ft_printf("%10.20f\n", 123.456);
		test_err(a, b);

		a = printf("%010.20f\n", 123.456);
		b = ft_printf("%010.20f\n", 123.456);
		test_err(a, b);

		a = printf("% 010.20f\n", 123.456);
		b = ft_printf("% 010.20f\n", 123.456);
		test_err(a, b);

		a = printf("% 10.20f\n", 123.456);
		b = ft_printf("% 10.20f\n", 123.456);
		test_err(a, b);

		a = printf("%-10.20f\n", 123.456);
		b = ft_printf("%-10.20f\n", 123.456);
		test_err(a, b);
    
    a = printf("%.20Lf\n", 123.456L);
    b = ft_printf("%.20Lf\n", 123.456L);
    test_err(a, b);
    
    a = printf("%30.20Lf\n", 123.456L);
    b = ft_printf("%30.20Lf\n", 123.456L);
    test_err(a, b);
    
    a = printf("%030.20Lf\n", 123.456L);
    b = ft_printf("%030.20Lf\n", 123.456L);
    test_err(a, b);
    
    a = printf("% 030.20Lf\n", 123.456L);
    b = ft_printf("% 030.20Lf\n", 123.456L);
    test_err(a, b);
    
    a = printf("% 30.20Lf\n", 123.456L);
    b = ft_printf("% 30.20Lf\n", 123.456L);
    test_err(a, b);
    
    a = printf("%-30.20Lf\n", 123.456L);
    b = ft_printf("%-30.20Lf\n", 123.456L);
    test_err(a, b);
    
    a = printf("%10.20Lf\n", 123.456L);
    b = ft_printf("%10.20Lf\n", 123.456L);
    test_err(a, b);
    
    a = printf("%010.20Lf\n", 123.456L);
    b = ft_printf("%010.20Lf\n", 123.456L);
    test_err(a, b);
    
    a = printf("% 010.20Lf\n", 123.456L);
    b = ft_printf("% 010.20Lf\n", 123.456L);
    test_err(a, b);
    
    a = printf("% 10.20Lf\n", 123.456L);
    b = ft_printf("% 10.20Lf\n", 123.456L);
    test_err(a, b);
    
    a = printf("%-10.20Lf\n", 123.456L);
    b = ft_printf("%-10.20Lf\n", 123.456L);
    test_err(a, b);
}
