/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:31:09 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 16:31:11 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	format_specifier(const char format, int count, va_list arg)
{
	if (format == 'c')
		ft_putchar(va_arg(arg, int));
	if (format == 's')
		ft_putstr(va_arg(arg, char *));
	if (format == 'p')
		count += putaddr((va_arg(arg, void *)), 0);
	if (format == 'd')
		count += putnbr_base(va_arg(arg, int), "0123456789", 's', 0);
	if (format == 'i')
		count += putnbr_base(va_arg(arg, int), "0123456789", 's', 0);
	if (format == 'u')
		count += putnbr_base(va_arg(arg, unsigned), "0123456789", 'u', 0);
	if (format == 'x')
		count += putnbr_base(va_arg(arg, int64_t), "0123456789abcdef", 's', 0);
	if (format == 'X')
		count += putnbr_base(va_arg(arg, int64_t), "0123456789ABCDEF", 's', 0);
	if (format == '%')
		ft_putchar('%');
	return (count);
}
