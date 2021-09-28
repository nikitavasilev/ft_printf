/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:52:48 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/29 01:25:27 by nvasilev         ###   ########.fr       */
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

typedef enum e_boolean {FALSE, TRUE}	t_boolean;

# define DEC "0123456789"
# define HEX_MAJ "0123456789ABCDEF"
# define HEX_MIN "0123456789abcdef"

# ifdef __linux__
#  define RET_NULL "(nil)"
# elif __APPLE__
#  define RET_NULL "0x0"
# else
#  define RET_NULL "(null)"
# endif

// LIBFT FUNCTIONS
int		ft_putchar(int c);
size_t	ft_putstr(char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		isnum(const char c);
int		ft_strcmp(char *s1, char *s2);

int		putnbr_base_s(int64_t n, const char *base, int count, int minus);
int		putnbr_base_u(size_t n, const char *base, int count);
int		putaddr(const void *p, int count);
int		check_null_p(void *p);
int		check_null_s(char *s);
size_t	count_chars(int64_t num, const char *base);

int		*zero_check(const char *format, int *count, va_list arg);

// ZERO CHECK UTILITIES
char	*create_base(const char *format, size_t i);
int64_t	cpy_list(const char *format, size_t i, va_list arg);
int		*print_minus(int *count, int64_t *num);
int		*print_zeros(int zeros, int64_t *num, char *base, int *count);
size_t	check_dot(const char *format, int *dot);

int		*minus_padding(const char *format, int *count, va_list arg);
void	sharp_check(const char *format, int *count, int64_t num, va_list arg);
void	space_and_sign(const char *form, int *count, int64_t num, va_list arg);

int		*dot_precision(const char *format, int *count, va_list arg);

// PARSERS
int		*precision_parser(const char *format, int *count, va_list arg);
int		format_specifier(const char format, int count, va_list arg);
int		ft_printf(const char *format, ...);

#endif
