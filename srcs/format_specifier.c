/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:31:09 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 23:23:12 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
