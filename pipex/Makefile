# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelet <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 08:37:01 by lbelet            #+#    #+#              #
#    Updated: 2021/12/07 09:20:14 by lbelet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = pipex
CFLAGS = -Wall -Wextra -Werror
SRC = ft_pipex.c ft_check_format.c ft_printf_int.c ft_printf_p.c ft_printf_utils.c ft_printf.c ft_pipex_basics.c ft_pipex_utils.c ft_erreurs.c ft_pipex_basics_bis.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
