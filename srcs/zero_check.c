/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:56:57 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 11:02:31 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	*zero_check(const char *format, int *count, va_list arg)
{
	size_t	i;
	int		zeros;
	int64_t	num;
	int		dot;
	char	*base;

	i = check_dot(format, &dot);
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
		|| format[i] == 'x' || format[i] == 'X')
	{
		base = create_base(format, i);
		num = cpy_list(format, i, arg);
		if (dot)
			format++;
		zeros = ft_atoi(format) - count_chars(num, base);
		if (num < 0 && base == DEC)
			count = print_minus(count, &num);
		count[1] += i;
		if (dot)
			zeros = ft_atoi(format) - count_chars(num, base);
		count = print_zeros(zeros, &num, base, count);
	}
	va_arg(arg, int);
	return (count);
}
