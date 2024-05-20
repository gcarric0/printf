/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:01:44 by gcarrico          #+#    #+#             */
/*   Updated: 2024/04/17 14:01:07 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*des;
	size_t				i;

	source = (const unsigned char *)src;
	des = (unsigned char *)dest;
	i = 0;
	if (des > source)
	{
		while (n-- > 0)
			des[n] = source[n];
	}
	else
	{
		while (i < n)
		{
			des[i] = source[i];
			i++;
		}
	}
	return (des);
}
