/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvasilev <nvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:58:29 by nvasilev          #+#    #+#             */
/*   Updated: 2021/09/14 23:56:58 by nvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

// http://www.firmcodes.com/write-printf-function-c/

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	va_start(arg, format);

	while (*format)
	{

	}

	va_end(arg);
}

int	main(void)
{
	char *str = "test";

	printf("c = %c\n", str[0]);
	printf("s = %s\n", str);
	printf("p = %p\n", str);
	printf("d = %d\n", 42);
	printf("i = %i\n", INT_MIN);
	printf("u = %u\n", UINT_MAX);
	printf("x = %x\n", 42);
	printf("X = %X\n", 42);
	printf("%% = %%\n");

	return (0);
}
