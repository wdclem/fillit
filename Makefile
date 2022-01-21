# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thule <thule@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 17:42:19 by thule             #+#    #+#              #
#    Updated: 2022/01/21 17:11:21 by ccariou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror #temp removed from first rule
NAME = fillit
FILES = main.c get_next_line.c make_tetri.c board.c
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
