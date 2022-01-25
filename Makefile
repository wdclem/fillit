# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thle <thle@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 17:42:19 by thule             #+#    #+#              #
#    Updated: 2022/01/25 15:40:31 by thle             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror #temp removed from first rule
NAME = fillit
FILES = main.c check_tetriminos.c helpers.c solver.c
OBJS = *.o

.PHONY: all $(NAME) clean fclean re
.SILENT: all $(NAME) clean fclean re

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(FILES) -Ilibft -Llibft -lft

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
