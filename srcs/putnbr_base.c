/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:30:01 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 21:57:03 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putnbr_base_s(int64_t n, const char *base, int count)
{
	int64_t	len;

	count++;
	len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		count++;
	}
	if (n >= len)
		count = putnbr_base_s(n / len, base, count);
	ft_putchar(base[n % len]);
	return (count);
}

int	putnbr_base_u(size_t n, const char *base, int count)
{
	size_t len;

	count++;
	len = ft_strlen(base);
	if (n >= len)
		count = putnbr_base_u(n / len, base, count);
	ft_putchar(base[n % len]);
	return (count);
}
