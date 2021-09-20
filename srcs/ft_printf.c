/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:53:06 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 20:11:14 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	arg;

	count = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += format_specifier(*format, count, arg);
			printf("\nCOUNT = %d\n", count);
		}
		else
		{
			ft_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(arg);
	return (count);
}
