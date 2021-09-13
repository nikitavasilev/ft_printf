/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:41:42 by nvasilev          #+#    #+#             */
/*   Updated: 2020/11/26 18:05:22 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	occ;

	occ = 0;
	while (*s)
	{
		if (*s == c)
			occ = 1;
		s++;
	}
	while (*s != c && occ)
		s--;
	if (*s == c)
		return ((char *)s);
	return (0);
}
