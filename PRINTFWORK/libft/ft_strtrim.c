/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:14:11 by gcarrico          #+#    #+#             */
/*   Updated: 2024/04/23 11:02:22 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	slen;
	size_t	j;
	size_t	i;
	char	*strim;

	i = 0;
	slen = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (slen > i && ft_strchr(set, s1[slen - 1]))
		slen--;
	strim = (char *)malloc(sizeof(char) * (slen - i + 1));
	if (!strim)
		return (NULL);
	j = 0;
	while (slen > i)
		strim[j++] = s1[i++];
	strim[j] = '\0';
	return (strim);
}
