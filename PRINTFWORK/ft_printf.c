/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:23:37 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/23 12:12:23 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list args, const char *format, int i)
{
	if (format[i + 1] == '%')
		return (ft_putchar(format[i + 1]));
	else if (format[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format[i + 1] == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (format[i + 1] == 'u')
		return (ft_printunbr(va_arg(args, unsigned int)));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
	{
		if (format[i + 1] == 'x')
			return (ft_printhex(va_arg(args, unsigned int),
					"0123456789abcdef"));
		else
			return (ft_printhex(va_arg(args, unsigned int),
					"0123456789ABCDEF"));
	}
	else if (format[i + 1 == 'p'])
		return (ft_print_pointer(va_arg(args, unsigned long long),
				"0123456789abcdef"));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			result = result + check_format(args, format, i);
			i++;
		}
		else
			result = result + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (result);
}
/*
#include <limits.h>
#include <stdio.h>

int	main(void) {
	ft_printf("Test Output:\n");
	ft_printf(" %%p: %p\n", (void *)-1);
	ft_printf(" %%p: %p\n", (void *)1);
	ft_printf(" %%p: %p\n", (void *)15);
	ft_printf(" %%p: %p\n", (void *)16);
	ft_printf(" %%p: %p\n", (void *)17);
	ft_printf(" %%p %%p: %p %p\n", (void *)LONG_MIN, (void *)LONG_MAX);
	ft_printf(" %%p %%p: %p %p\n", (void *)INT_MIN, (void *)INT_MAX);
	ft_printf(" %%p %%p: %p %p\n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
	ft_printf(" %%p %%p: %p %p\n", (void *)0, (void *)0);

	return (0);
} */

/* #include <stdio.h>
#include <limits.h>

int	main(void) {
	ft_printf("Test Output:\n");
	ft_printf(" %%u: %u\n", (unsigned int)-1);
	ft_printf(" %%u: %u\n", (unsigned int)0);
	ft_printf(" %%u: %u\n", (unsigned int)15);
	ft_printf(" %%u: %u\n", (unsigned int)16);
	ft_printf(" %%u: %u\n", (unsigned int)17);
	ft_printf(" %%u %%u: %u %u\n", (unsigned int)LONG_MIN,
		(unsigned int)LONG_MAX);
	ft_printf(" %%u %%u: %u %u\n", (unsigned int)INT_MIN,
		(unsigned int)INT_MAX);
	ft_printf(" %%u %%u: %u %u\n", (unsigned int)ULONG_MAX,
		(unsigned int)-ULONG_MAX);
	ft_printf(" %%u %%u: %u %u\n", (unsigned int)0, (unsigned int)0);

	return (0);
} */
