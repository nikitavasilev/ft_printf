/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:58:29 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 10:48:07 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	char	*str;

	str = "test";
	char c = 'j';

	//printf("RET: %d\n", printf(" %+i ", 0));
	printf("RET: %d\n", ft_printf("% s", ""));
	//printf("RET: %d\n", ft_printf(" %+d ", -1));
	//printf("RET: %d\n", printf(" %#x%#x ", INT_MAX, INT_MIN));
	//printf("RET: %d\n", printf(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	//printf("RET: %d\n", ft_printf(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	//printf("RET: %d\n", ft_printf(" %#x ", 0));
	//printf("RET: %d\n", printf("%010i\n", 25987));
	//printf("RET: %d\n", ft_printf("%010i\n", 25987));
	//printf("RET: %d\n", printf("%.2s\n", str));
	//printf("RET: %d\n", ft_printf("%.2s\n", str));
	//printf("RET: %d\n", printf(" %-s ", "-"));
	//printf("RET: %d\n", ft_printf(" %.4d ", -14));
	//printf("RET: %d\n", ft_printf(" %03d ", -11));
	//printf("RET: %d\n", printf(" %.2s %.1s ", "test", "-"));
	//printf("RET: %d\n", ft_printf(" %.1s ", "-"));
	//printf("RET: %d\n", printf("%0.10x str= %s\n", -42, str));
	//printf("RET: %d\n", ft_printf("%0.10x str= %s\n", -42, str));
	//printf("RET: %d\n", ft_printf("str= %s\n", "yes"));
	//ft_printf("\ns = %s (ft_printf)\n", str);
	//printf("s = %s (printf)\n", str);
/*
	ft_printf("TESTER (ft_printf):\n");
	printf("return: %d\n\n", ft_printf(" NULL %s NULL ", NULL));
	printf("return: %d\n\n", ft_printf(" %p %p ", NULL, NULL));

	printf("\nTESTER (printf):\n");
	printf("return: %d\n\n", printf(" NULL %s NULL ", NULL));
	printf("return: %d\n\n", printf(" %p %p ", NULL, NULL));

	ft_printf("\nc = %c (ft_printf)\n", str[0]);
	printf("c = %c (printf)\n", str[0]);

	ft_printf("\ns = %s (ft_printf)\n", str);
	printf("s = %s (printf)\n", str);

	ft_printf("\np = %p (ft_printf)\n", &str);
	printf("p = %p (printf)\n", &str);

	printf("\nd = %d (printf)\n", 0000000000101010);
	ft_printf("d = %d (ft_printf)\n", 0000000000101010);

	ft_printf("\ni = %i (ft_printf)\n", 042);
	printf("i = %i (printf)\n", 042);

	ft_printf("\nu = %u (ft_printf)\n", -42);
	printf("u = %u (printf)\n", -42);

	ft_printf("\nx = %x (ft_printf)\n", 42);
	printf("x = %x (printf)\n", 42);

	ft_printf("\nX = %X (ft_printf)\n", -42);
	printf("X = %X (printf)\n", -42);

	ft_printf("\n%% = %% (ft_printf)\n");
	printf("%% = %% (printf)");
	printf("\n");

	ft_printf("\nMIX: (ft_printf)");
	ft_printf("\nRETURN: %d", ft_printf("\nNombre: %d, adresse: %p, percent: %%", 42, &str));

	printf("\n\nMIX: (printf)");
	printf("\nRETURN: %d", printf("\nNombre: %d, adresse: %p, percent: %%", 42, &str));
*/
	return (0);
}
