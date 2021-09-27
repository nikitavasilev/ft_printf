/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:08:23 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 11:08:32 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	sharp_check(const char *format, int *count, int64_t num, va_list arg)
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
