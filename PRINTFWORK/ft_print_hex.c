/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:52:55 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/21 10:12:18 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned int n)
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

static char	*puthex(unsigned int n, char *base)
{
	int		size;
	char	*hexstr;

	size = count_hex(n);
	hexstr = (char *)malloc(sizeof(char) * (size + 1));
	if (!hexstr)
		return (NULL);
	hexstr[size] = '\0';
	while (size > 0)
	{
		hexstr[size - 1] = base[n % 16];
		n = n / 16;
		size--;
	}
	return (hexstr);
}

int	ft_printhex(unsigned int nbr, char *base)
{
	char	*str;
	int		len;

	str = puthex(nbr, base);
	len = ft_printstr(str);
	free(str);
	return (len);
}
