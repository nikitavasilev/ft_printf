/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:53:06 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 10:57:07 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_arr(int *arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		count[2];
	int		*tmp;
	va_list	arg;

	init_arr(count, 2);
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '.' || *format == '0' || *format == '-' || *format == '#' || *format == '+' || *format == ' ')
			{
				tmp = bonus_check(format, count, arg);
				count[0] = tmp[0];
				if (*format == '#' || *format == '+' || *format == ' ')
					format++;
				else
					format += tmp[1];
			}
			else
				count[0] += format_specifier(*format, count[0], arg);
		}
		else
		{
			ft_putchar(*format);
			count[0]++;
		}
		format++;
	}
	va_end(arg);
	return (count[0]);
}
