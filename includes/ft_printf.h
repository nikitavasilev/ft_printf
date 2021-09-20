/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:52:48 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/20 23:30:11 by nvasilev         ###   ########.fr       */
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

# ifdef __linux__
#  define RET_NULL "(nil)"
# else
#  define RET_NULL "(null)"
# endif

int		ft_putchar(int c);
size_t	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		putnbr_base_s(int64_t n, const char *base, int count);
int		putnbr_base_u(size_t n, const char *base, int count);
int		putaddr(const void *p, int count);
int		check_null_p(void *p);
int		check_null_s(char *s);
int		format_specifier(const char format, int count, va_list arg);
int		ft_printf(const char *format, ...);

#endif
