/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:59:37 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 11:00:17 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	dot_str_check(size_t i, const char *format, int *count, va_list arg)
{
	va_list	cpy;
	char	*str;
	int		precision;
	int		j;

	va_copy(cpy, arg);
	str = va_arg(cpy, char *);
	va_arg(arg, char *);
	precision = ft_atoi(format + 1);
	j = 0;
	while (str[j] && j < precision)
	{
		ft_putchar(str[j]);
		j++;
	}
	count[1] = i;
	count[0] += j;
	return (i);
}

int	*dot_precision(const char *format, int *count, va_list arg)
{
	size_t	i;

	i = 1;
	while (ft_isdigit(format[i]))
		i++;
	if (format[i] == 's')
		i = dot_str_check(i, format, count, arg);
	else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
		|| format[i] == 'x' || format[i] == 'X')
		return (zero_check(format, count, arg));
	return (count);
}
