/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:53:06 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/23 02:52:30 by nvasilev         ###   ########.fr       */
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
			tmp = bonus_check(format, count, arg);
			count[0] = tmp[0];
			format += tmp[1];
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
