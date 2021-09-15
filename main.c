/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:58:29 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/15 20:07:34 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "includes/ft_printf.h"

// http://www.firmcodes.com/write-printf-function-c/

/*
int	ft_printf(const char *format, ...)
{
	va_list	arg;
	va_start(arg, format);

	while (*format)
	{

	}

	va_end(arg);
}
*/

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
}

void	dec_to_hex(ssize_t nb, char format)
{
	const char	*base16;

	if (format == 'X')
		base16 = "0123456789ABCDEF";
	else
		base16 = "0123456789abcdef";
	if (nb >= 16)
	{
		dec_to_hex(nb / 16, format);
	}
	ft_putchar(base16[nb % 16]);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if ((unsigned int)n >= 10)
		ft_putnbr((unsigned int)n / 10);
	ft_putchar((unsigned int)n % 10 + '0');
}

void	ft_putnbr_u(unsigned int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	putnbr_base(long long n, const char *base, char sign)
{
	size_t	len;

	len = ft_strlen(base);
	if (len == 16 || sign == 'u')
		n = (unsigned)n;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= len)
		putnbr_base(n / len, base, sign);
	ft_putchar(base[n % len]);
}

void	putaddr(void *p)
{
	unsigned int addr;

	addr = (unsigned int)&p;
	putnbr_base(addr, "0123456789abcdef", 'u');
}

int	main(void)
{
	char *str = "test";
	int	nb = 42;

	printf("c = %c (printf)\n", str[0]);
	ft_putstr("c = ");
	ft_putchar(str[0]);
	ft_putstr(" (ft_putchar)");

	printf("\n\ns = %s (printf)\n", str);
	ft_putstr("s = ");
	ft_putstr(str);
	ft_putstr(" (ft_putstr)");

	printf("\n\np = %p (printf)\n", &str);
	putaddr(&str);

	printf("\n\nd = %d (printf)\n", INT_MAX + 1000);
	ft_putstr("d = ");
	putnbr_base(INT_MAX + 1000, "0123456789", 's');
	ft_putstr(" (putnbr_base)");

	printf("\n\ni = %i (printf)\n", INT_MIN);
	ft_putstr("i = ");
	putnbr_base(INT_MIN, "0123456789", 's');
	ft_putstr(" (putnbr_base)");

	printf("\n\nu = %u (printf)\n", -42);
	ft_putstr("u = ");
	putnbr_base(-42, "0123456789", 'u');
	ft_putstr(" (putnbr_base)");

	printf("\n\nx = %x (printf)\n", nb);
	ft_putstr("x = ");
	putnbr_base(nb, "0123456789abcdef", 's');
	ft_putstr(" (putnbr_base)");

	printf("\n\nX = %X (printf)\n", -nb);
	ft_putstr("X = ");
	putnbr_base(-nb, "0123456789ABCDEF", 's');
	ft_putstr(" (putnbr_base)");

	printf("\n\n%% = %% (printf)\n");
	ft_putstr("% = ");
	ft_putchar('%');
	ft_putstr(" (ft_putchar)");

	return (0);
}
