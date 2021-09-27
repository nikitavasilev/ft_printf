/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 07:22:50 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/27 07:23:06 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	count_chars(int64_t num, const char *base)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(base);
	if (len == 16)
		num = (unsigned)num;
	i = 0;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num)
	{
		num /= len;
		i++;
	}
	return (i);
}
