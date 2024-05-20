/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:23:37 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/20 11:49:41 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_format(va_list args, const char *format, int i);

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
	}
	va_end(args);
	return (result);
}

int	check_format(va_list args, const char *format, int i)
{
	i = 0;
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
			return (ft_printhex(va_arg(args, unsigned int), "0123456789abcdef"));
		else
			return (ft_printhex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	}
	else if (format[i + 1 == 'p'])
		return (ft_printstr("0x") + ft_print_pointer(va_arg(args, void *),
				"0123456789abcdef"));
	else
		return (0);
}
