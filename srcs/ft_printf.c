/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:53:06 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 10:50:55 by nvasilev         ###   ########.fr       */
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

const char	*prec_and_padd(int *count, int *tmp, const char *form, va_list arg)
{
	if (*form == '.' || *form == '0' || *form == '-'
		|| *form == '#' || *form == '+' || *form == ' ')
	{
		tmp = precision_parser(form, count, arg);
		count[0] = tmp[0];
		if (*form == '#' || *form == '+' || *form == ' ')
			form++;
		else
			form += tmp[1];
	}
	else
		count[0] += format_specifier(*form, count[0], arg);
	return (form);
}

int	ft_printf(const char *format, ...)
{
	int		count[2];
	int		*tmp;
	va_list	arg;

	tmp = NULL;
	init_arr(count, 2);
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format = prec_and_padd(count, tmp, format, arg);
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
