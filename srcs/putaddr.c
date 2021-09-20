/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putaddr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:30:33 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 21:19:26 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putaddr(const void *p, int count)
{
	uintmax_t	addr;

	addr = (uintmax_t)p;
	ft_putstr("0x");
	count += putnbr_base(addr, HEX_MIN, 'p', count) + 2;
	 return (count);
}
