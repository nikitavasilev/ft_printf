/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_and_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:08:59 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 11:09:13 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	space_and_sign(const char *format, int *count, int64_t num, va_list arg)
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
