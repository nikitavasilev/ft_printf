/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:35:13 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/13 22:18:19 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_chars(int num)
{
	size_t	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	str_fill(char *str, int num, size_t i)
{
	unsigned int	n;

	n = num;
	if (num < 0)
		n = num * -1;
	if (n >= 10)
		str_fill(str, n / 10, i - 1);
	str[i] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	length;

	length = count_chars(n);
	res = malloc(length + 1);
	if (!res)
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		str_fill(&res[1], n, length - 2);
	}
	else
		str_fill(res, n, length - 1);
	res[length] = '\0';
	return (res);
}
