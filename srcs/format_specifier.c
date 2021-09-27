/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:31:09 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 10:42:57 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	count_chars(int64_t num, const char *base)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(base);
	if (len == 16)
		num = (unsigned)num;
	i = 0;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num)
	{
		num /= len;
		i++;
	}
	return (i);
}

int	putnbr_base_minus(int64_t n, const char *base, int count)
{
	int64_t	len;

	count++;
	len = ft_strlen(base);
	if (len == 16)
		n = (unsigned)n;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n >= len)
		count = putnbr_base_s(n / len, base, count);
	ft_putchar(base[n % len]);
	return (count);
}

int	*print_zeros(const char *format, int *count, va_list arg)
{
	size_t	i;
	int		zeros;
	va_list	tmp;
	int64_t	num;
	int		dot;
	char	*base;

	dot = FALSE;
	if (format[0] == '.')
		dot = TRUE;
	i = 1;
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
	{
		va_copy(tmp, arg);
		if (format[i] == 'x')
			base = HEX_MIN;
		else if (format[i] == 'X')
			base = HEX_MAJ;
		else
			base = DEC;
		if (format[i] == 'u')
			num = va_arg(tmp, unsigned);
		else if (format[i] == 'd' || format[i] == 'i')
			num = va_arg(tmp, int);
		else
			num = va_arg(tmp, int64_t);
		if (dot)
			format++;
		if (!dot)
			zeros = ft_atoi(format) - count_chars(num, base);
		if (num < 0 && base == DEC)
		{
			ft_putchar('-');
			count[0]++;
			num *= -1;
		}
		count[1] += i;
		if (dot)
			zeros = ft_atoi(format) - count_chars(num, base);
		if (zeros >= 0)
		{
			if (count_chars(num, base))
				count[0] += zeros;
			else
				count[0] += (zeros - 1);
		}
		if (zeros >= 0 && count_chars(num, base))
		{
			while (zeros--)
				ft_putchar('0');
		}
		if (format[i] == 'u')
			count[0] += putnbr_base_minus(num, base, 0);
		else
			count[0] += putnbr_base_minus(num, base, 0);
	}
	va_arg(arg, int);
	return (count);
}

int	*dot_precision(const char *format, int *count, va_list arg)
{
	size_t	i;
	int		j;
	int		precision;
	va_list	cpy;
	char	*str;

	i = 1;
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == 's')
	{
		va_copy(cpy, arg);
		str = va_arg(cpy, char *);
		va_arg(arg, char *);
		precision = ft_atoi(format + 1);
		j = 0;
		while (str[j] && j < precision)
		{
			ft_putchar(str[j]);
			j++;
		}
		count[1] = i;
		count[0] += j;
	}
	else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
		return (print_zeros(format, count, arg));
	return (count);
}

int	*minus_padding(const char *format, int *count, va_list arg)
{
	size_t	i;
	int		spaces;
	int		len;

	i = 1;
	while (ft_isdigit(format[i]))
		i++;
	len = format_specifier(format[i], count[0], arg);
	spaces = ft_atoi(++format) - len;
	if (spaces > 0)
		count[0] += (spaces + len);
	else
		count[0] += len;
	count[1] = i;
	while (spaces > 0 && spaces--)
		ft_putchar(' ');
	return (count);
}

int	*bonus_check(const char *format, int *count, va_list arg)
{
	va_list	tmp;
	int64_t	num;

	va_copy(tmp, arg);
	num = va_arg(tmp, int64_t);
	if (format[0] == '0' && format[1] == '.')
	{
		count[1]++;
		return (dot_precision(&format[1], count, arg));
	}
	if (format[0] == '0')
		return (print_zeros(format, count, arg));
	if (format[0] == '.')
		return (dot_precision(format, count, arg));
	if (format[0] == '-')
		return (minus_padding(format, count, arg));
	if (format[0] == '#')
	{
		if (num && num != LONG_MIN)
		{
			if (format[1] == 'x')
				ft_putstr("0x");
			if (format[1] == 'X')
				ft_putstr("0X");
			if (format[1] == 'x' || format[1] == 'X')
				count[0] += 2;
		}
		count[0] += format_specifier(format[1], count[0], arg);
		count[1]++;
	}
	if ((format[0] == '+' || format[0] == ' ') && (format[1] == 'd' || format[1] == 'i'))
	{
		if ((int)num >= 0)
		{
			if (format[0] == '+')
				ft_putchar('+');
			if (format[0] == ' ')
				ft_putchar(' ');
			count[0]++;
		}
		count[0] += format_specifier(format[1], count[0], arg);
		count[1]++;
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
