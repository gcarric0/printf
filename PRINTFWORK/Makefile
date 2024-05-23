# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcarrico <gcarrico@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 11:30:57 by gcarrico          #+#    #+#              #
#    Updated: 2024/05/23 09:58:10 by gcarrico         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CFLAGS			= -Wall -Wextra -Werror
CC				= cc
RM				= rm -f

LIBFT_DIR		= ./libft
LIBFT			= ./libft/libft.a

FT_PRINTF		=  ft_print_hex.c ft_print_pointer.c ft_print.c ft_printf.c \

OBJECTS			= $(FT_PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJECTS)

$(LIBFT): $(LIBFT_DIR)
	@$(MAKE) -C $(LIBFT_DIR)

%.o:%.c
	@$(CC) -c $(CFLAGS) $?

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(RM) $(OBJECTS)

fclean:		clean
			@$(MAKE) fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)
			

re: fclean all

.PHONY: all re clean fclean