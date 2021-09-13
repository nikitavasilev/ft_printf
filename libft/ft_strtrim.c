/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:14:35 by nvasilev          #+#    #+#             */
/*   Updated: 2020/12/20 17:45:09 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] && in_set(s1[i], set))
		i++;
	end = ft_strlen(s1);
	while (end > i && in_set(s1[end - 1], set))
		end--;
	if (!(str = malloc(end - i + 1)))
		return (0);
	j = 0;
	while (i + j < end)
	{
		str[j] = s1[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
