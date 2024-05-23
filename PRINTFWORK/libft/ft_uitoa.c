/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:19:42 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/23 11:28:52 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ucount_digits(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		ndigits;

	ndigits = ucount_digits(n);
	str = (char *)malloc(sizeof(char) * (ndigits + 1));
	if (!str)
		return (0);
	str[ndigits] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n != 0)
	{
		str[ndigits - 1] = n % 10 + '0';
		n = n / 10;
		ndigits--;
	}
	return (str);
}
