/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:28:58 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/06 10:41:52 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dupstr;

	len = ft_strlen(s) + 1;
	dupstr = (char *)malloc(len * sizeof(char));
	if (!(dupstr))
		return (NULL);
	if (!ft_memcpy(dupstr, s, len))
	{
		free(dupstr);
		return (NULL);
	}
	return (dupstr);
}
