/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:14:19 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/23 11:28:42 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	size_t	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int	ft_printnbr(int nbr)
{
	char	*str;
	size_t	len;

	str = ft_itoa(nbr);
	len = ft_printstr(str);
	free(str);
	return (len);
}

int	ft_printunbr(unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_uitoa(nbr);
	len = ft_printstr(str);
	free(str);
	return (len);
}
