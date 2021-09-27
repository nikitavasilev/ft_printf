/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:07:48 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 11:07:55 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
