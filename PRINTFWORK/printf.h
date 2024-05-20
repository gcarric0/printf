/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:23:04 by gcarrico          #+#    #+#             */
/*   Updated: 2024/05/20 11:48:47 by gcarrico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printstr(char *str);
int	ft_putchar(char c);
int	ft_printunbr(unsigned int nbr);
int	ft_printnbr(int nbr);
int	ft_print_pointer(void *nbr, char *base);
int	ft_printf(const char *format, ...);
int	ft_printhex(unsigned int nbr, char *base);

#endif