/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:36:51 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/13 22:21:52 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (!len || src == dst)
		return (dst);
	if (d > s)
	{
		d += len - 1;
		s += len - 1;
		while (len--)
			*d-- = *s--;
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
