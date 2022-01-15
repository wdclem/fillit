# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thule <thule@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 17:42:19 by thule             #+#    #+#              #
#    Updated: 2022/01/14 10:58:03 by thule            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror #temp removed from first rule
NAME = fillit
FILES = main.c check_tetriminos.c
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
