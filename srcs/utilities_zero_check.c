/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_zero_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:01:48 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 11:02:38 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*create_base(const char *format, size_t i)
{
	char	*base;

	if (format[i] == 'x')
		base = HEX_MIN;
	else if (format[i] == 'X')
		base = HEX_MAJ;
	else
		base = DEC;
	return (base);
}

int64_t	cpy_list(const char *format, size_t i, va_list arg)
{
	int64_t	num;
	va_list	tmp;

	va_copy(tmp, arg);
	if (format[i] == 'u')
		num = va_arg(tmp, unsigned);
	else if (format[i] == 'd' || format[i] == 'i')
		num = va_arg(tmp, int);
	else
		num = va_arg(tmp, int64_t);
	return (num);
}

int	*print_minus(int *count, int64_t *num)
{
	ft_putchar('-');
	count[0]++;
	*num *= -1;
	return (count);
}

int	*print_zeros(int zeros, int64_t *num, char *base, int *count)
{
	if (zeros >= 0)
	{
		if (count_chars(*num, base))
		{
			count[0] += zeros;
			while (zeros--)
				ft_putchar('0');
		}
		else
			count[0] += (zeros - 1);
	}
	count[0] += putnbr_base_s(*num, base, 0, FALSE);
	return (count);
}

size_t	check_dot(const char *format, int *dot)
{
	size_t	i;

	*dot = FALSE;
	if (format[0] == '.')
		*dot = TRUE;
	i = 1;
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}
