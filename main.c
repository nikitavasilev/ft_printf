/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:58:29 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/23 03:03:48 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	char	*str;

	str = "test";

	printf("RET: %d\n", printf("%010i\n", 25987));
	printf("RET: %d\n", printf("%.2s\n", str));
	printf("RET: %d\n", ft_printf("%010i\n", 25987));
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
