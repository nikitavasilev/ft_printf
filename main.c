/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:58:29 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 23:32:17 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	char	*str;

	str = "test";
	//printf("MINE:\n");
	//printf("\nRETURN: %d\n\n", ft_printf("Nombre: %d, adresse: %p, percent: %%", 42, &str));

	ft_putstr("TESTER (ft_printf):\n");
	printf("return: %d\n\n", ft_printf(" NULL %s NULL ", NULL));
	printf("return: %d\n\n", ft_printf(" %p %p ", 0, 0));
	//printf("\nRETURN: %d\n\n", ft_printf("Adresse: %p", &str));
	//printf("\nRETURN: %d\n\n", ft_printf("M%d", 4243));
	//printf("REAL ONE:\n");
	//printf("\nRETURN: %d\n\n", printf("Nombre: %d, adresse: %p, percent: %%", 42, &str));
	printf("\nTESTER (printf):\n");
	printf("return: %d\n\n", printf(" NULL %s NULL ", NULL));
	printf("return: %d\n\n", printf(" %p %p ", 0, 0));
	//printf("\nRETURN: %d\n\n", printf("Adresse: %p", &str));
	//printf("\nRETURN: %d\n\n", printf("M%d", 4243));

	/*
	printf("\n\nc = %c (printf)\n", str[0]);
	ft_putstr("c = ");
	ft_putchar(str[0]);
	ft_putstr(" (ft_putchar)");

	printf("\n\ns = %s (printf)\n", str);
	ft_putstr("s = ");
	ft_putstr(str);
	ft_putstr(" (ft_putstr)");

	printf("\n\np = %p (printf)\n", &str);
	ft_putstr("p = ");
	putaddr(&str);
	ft_putstr(" (ft_putaddr)");

	printf("\n\nd = %d (printf)\n", 0000000000101010);
	ft_putstr("d = ");
	putnbr_base(0000000000101010, "0123456789", 's');
	ft_putstr(" (putnbr_base)");

	printf("\n\ni = %i (printf)\n", 042);
	ft_putstr("i = ");
	putnbr_base(042, "0123456789", 's');
	ft_putstr(" (putnbr_base)");

	printf("\n\nu = %u (printf)\n", -42);
	ft_putstr("u = ");
	putnbr_base(-42, "0123456789", 'u');
	ft_putstr(" (putnbr_base)");
*/
	printf("\n\nx = %x (printf)\n", 42);
	ft_putstr("x = ");
	putnbr_base_s(42, "0123456789abcdef", 0);
	ft_putstr(" (putnbr_base)");

	printf("\n\nX = %X (printf)\n", -42);
	ft_putstr("X = ");
	putnbr_base_s(-42, "0123456789ABCDEF", 0);
	ft_putstr(" (putnbr_base)");

	printf("\n\n%% = %% (printf)\n");
	ft_putstr("% = ");
	ft_putchar('%');
	ft_putstr(" (ft_putchar)");


	return (0);
}
