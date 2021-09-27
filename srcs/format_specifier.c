/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:31:09 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 11:09:18 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	*precision_parser(const char *format, int *count, va_list arg)
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
		return (zero_check(format, count, arg));
	if (format[0] == '.')
		return (dot_precision(format, count, arg));
	if (format[0] == '-')
		return (minus_padding(format, count, arg));
	if (format[0] == '#')
		sharp_check(format, count, num, arg);
	if ((format[0] == '+' || format[0] == ' ')
		&& (format[1] == 'd' || format[1] == 'i'))
		space_and_sign(format, count, num, arg);
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
		count = putnbr_base_s(va_arg(arg, int), DEC, 0, TRUE);
	if (format == 'i')
		count = putnbr_base_s(va_arg(arg, int), DEC, 0, TRUE);
	if (format == 'u')
		count = putnbr_base_u(va_arg(arg, unsigned), DEC, 0);
	if (format == 'x')
		count = putnbr_base_s(va_arg(arg, int64_t), HEX_MIN, 0, FALSE);
	if (format == 'X')
		count = putnbr_base_s(va_arg(arg, int64_t), HEX_MAJ, 0, FALSE);
	if (format == '%')
		ft_putchar('%');
	if (format == 'c' || format == '%')
		count = 1;
	return (count);
}
