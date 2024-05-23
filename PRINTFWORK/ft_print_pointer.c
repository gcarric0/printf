/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:31:28 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/23 12:12:04 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static char	*put_hex(unsigned long n, char *base)
{
	int		size;
	char	*hex;

	size = count_hex(n);
	hex = (char *)malloc(sizeof(char) * (size + 1));
	if (!hex)
		return (NULL);
	hex[size] = '\0';
	while (size > 0)
	{
		hex[size - 1] = base[n % 16];
		n = n / 16;
		size--;
	}
	return (hex);
}

int	ft_print_pointer(unsigned long long ptr, char *base)
{
	int		len;
	char	*str;

	if (ptr == 0 || !ptr)
		return (ft_printstr("(nil)"));
	len = ft_printstr("0x");
	str = put_hex(ptr, base);
	if (!str)
		return (0);
	len += ft_printstr(str);
	free(str);
	return (len);
}
