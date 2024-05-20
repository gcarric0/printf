/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:55:45 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/06 16:12:37 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dupstr;

	if (size > 0)
	{
		if ((nmemb > ((size_t) - 1 / size)) && size)
			return (NULL);
	}
	dupstr = malloc(nmemb * size);
	if (!dupstr)
		return (NULL);
	ft_bzero(dupstr, nmemb * size);
	return (dupstr);
}
