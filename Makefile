# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thule <thule@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 17:42:19 by thule             #+#    #+#              #
#    Updated: 2022/02/08 16:10:27 by thule            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fillit
FILES = main.c reader.c solver.c board.c
INCLUDE = fillit.h
LIB = libft/libft.a
OBJ = $(FILES:%.c=%.o)

.PHONY: all clean fclean re
.SILENT: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIB)

$(LIB): $(wildcard libft/*.o)
	$(MAKE) -sC ./libft

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(MAKE) -sC ./libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	$(MAKE) -sC ./libft fclean
	/bin/rm -f $(NAME)

re: fclean all
