/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:31:28 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/20 11:49:10 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	count_hex(unsigned long long n)
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

static char	*puthex(unsigned long n, char *base)
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

int	ft_print_pointer(void *nbr, char *base)
{
	size_t			len;
	char			*str;
	unsigned long	n;

	n = (unsigned long)nbr;
	str = puthex(n, base);
	len = ft_printstr(str);
	free(str);
	return (len);
}
