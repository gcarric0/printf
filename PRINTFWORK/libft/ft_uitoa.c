/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:19:42 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/20 09:17:46 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_digits(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char *str;
	size_t ndigits;
	unsigned nbr;

	ndigits = count_digits(n);
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		ndigits++;
	}
	str = (char *)malloc(sizeof(char) * (ndigits + 1));
	if (!str)
		return (NULL);
	str[ndigits] = '\0';
	while (ndigits--)
	{
		str[ndigits] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}