/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:52:48 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 17:18:16 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>

int		ft_putchar(int c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		putnbr_base(int64_t n, const char *base, const char sign, int count);
int		putaddr(const void *p, int count);
int		format_specifier(const char format, int count, va_list arg);
int		ft_printf(const char *format, ...);

#endif
