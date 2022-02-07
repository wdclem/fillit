# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thle <thle@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 17:42:19 by thule             #+#    #+#              #
#    Updated: 2022/02/07 17:11:09 by thle             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fillit
FILES = main.c reader.c solver.c board.c
OBJS = *.o

#.PHONY: all $(NAME) clean fclean re
#.SILENT: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(FILES)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) $(FLAGS) $(FILES) -Ilibft -Llibft -lft

clean:
	/bin/rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all
	$(MAKE) -C ./libft re
