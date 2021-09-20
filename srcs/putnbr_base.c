/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:30:01 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 21:16:25 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putnbr_base(intmax_t n, const char *base, const char sign, int count)
{
	int64_t	len;

	count++;
	len = ft_strlen(base);
	if (sign == 'p')
		n = (uintmax_t)n;
	else if (len == 16 || sign == 'u')
		n = (unsigned)n;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		count++;
	}
	if (n >= len)
		count = putnbr_base(n / len, base, sign, count);
	ft_putchar(base[n % len]);
	return (count);
}
