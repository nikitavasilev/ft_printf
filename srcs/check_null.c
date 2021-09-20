/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:11:25 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 23:29:06 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_null_s(char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	else
		return (ft_putstr(s));
}

int	check_null_p(void *p)
{
	if (!p)
		return (ft_putstr(RET_NULL));
	else
		return (putaddr(p, 0));
}
