/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:31:09 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/23 02:54:58 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	isnum(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static size_t	count_chars(int num)
{
	size_t i;

	i = 0;
	if (num <= 0)
		i++;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	*bonus_check(const char *format, int *count, va_list arg)
{
	size_t	i;
	int		zeros;
	va_list	num;
	int		n;

	if (*format == '0')
	{
		i = 1;
		while (isnum(format[i]))
			i++;
		if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
		{
			va_copy(num, arg);
			n = va_arg(num, int);
			zeros = atoi(format) - count_chars(n);

			format += i;
			count[1] = i;
			count[0] = zeros;
			while (zeros--)
				ft_putchar('0');
			count[0] += format_specifier(*format, zeros, arg);
		}
	}
	return (count);
}

int	format_specifier(const char format, int count, va_list arg)
{
	if (format == 'c')
		ft_putchar(va_arg(arg, int));
	if (format == 's')
		count = check_null_s(va_arg(arg, char *));
	if (format == 'p')
		count = check_null_p(va_arg(arg, void *));
	if (format == 'd')
		count = putnbr_base_s(va_arg(arg, int), DEC, 0);
	if (format == 'i')
		count = putnbr_base_s(va_arg(arg, int), DEC, 0);
	if (format == 'u')
		count = putnbr_base_u(va_arg(arg, unsigned), DEC, 0);
	if (format == 'x')
		count = putnbr_base_s(va_arg(arg, int64_t), HEX_MIN, 0);
	if (format == 'X')
		count = putnbr_base_s(va_arg(arg, int64_t), HEX_MAJ, 0);
	if (format == '%')
		ft_putchar('%');
	if (format == 'c' || format == '%')
		count = 1;
	return (count);
}
