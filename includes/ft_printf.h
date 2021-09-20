/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:52:48 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 20:55:42 by nvasilev         ###   ########.fr       */
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

# define DEC "0123456789"
# define HEX_MAJ "0123456789ABCDEF"
# define HEX_MIN "0123456789abcdef"

int		ft_putchar(int c);
size_t	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		putnbr_base(intmax_t n, const char *base, const char sign, int count);
int		putaddr(const void *p, int count);
int		format_specifier(const char format, int count, va_list arg);
int		ft_printf(const char *format, ...);

#endif
