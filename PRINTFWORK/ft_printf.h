/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:23:04 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/23 12:10:03 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printstr(char *str);
int	ft_putchar(char c);
int	ft_printunbr(unsigned int nbr);
int	ft_printnbr(int nbr);
int	ft_printf(const char *format, ...);
int	ft_printhex(unsigned int nbr, char *base);
int	ft_print_pointer(unsigned long long ptr, char *base);

#endif