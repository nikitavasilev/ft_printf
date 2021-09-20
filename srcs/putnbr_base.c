/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:30:01 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 17:14:16 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putnbr_base(int64_t n, const char *base, const char sign, int count)
{
	int64_t	len;

	len = ft_strlen(base);
	if (sign == 'p')
		n = (uint64_t)n;
	else if (len == 16 || sign == 'u')
		n = (unsigned)n;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= len)
	{
		count += putnbr_base(n / len, base, sign, count);
		count++;
	}
	ft_putchar(base[n % len]);
	return (count);
}
