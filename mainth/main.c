/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/20 14:35:10 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //rmb to delete
#include "fillit.h"

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

int	place_on_board(char **board, int *shape, int x, int y, char c)
{
	//RETURN 0 IF CANT PLACE
	//RETURN 1 IF PLACE SUCCESSFULLY
	//max = ft_strlen(*board) - (x or y + 1)
	//apply onto a new array? 
	int index;
	int pos_x;
	int pos_y;

	index = 0;
	pos_x = 0;
	pos_y = 0;
	while (index < 8)
	{
		pos_x = shape[index] + x;
		index++;
		pos_y = shape[index] + y;
		index++;
		board[pos_x][pos_y] = c;
	}
	while (*board)
	{
		printf("%s\n", *board);
		board++;
	}
	return (1);
}

int	*check_piece(char **arr)
{
	int x = 0;
	int y = 0;
	int xmin = 3;
	int ymin = 3;
	int counter = 0;
	int index = 0;
	int *shape = (int *) malloc (sizeof(int) * 8);

	x = 0;
	y = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (arr[x][y] == '#')
			{
				if (x < xmin)
					xmin = x;
				if (y < ymin)
					ymin = y;
				if (x != 0 && arr[x - 1][y] == '#')
					counter++;
				if (x != 3 && arr[x + 1][y] == '#')
					counter++;
				if (y != 0 && arr[x][y - 1] == '#')
					counter++;
				if (y != 3 && arr[x][y + 1] == '#')
					counter++;
				shape[index] = x;
				index++;
				shape[index] = y;
				index++;
			}
			y++;
		}
		x++;
	}
	index = 0;
	while (index < 8)
	{
		if (index % 2 == 0)
			shape[index] = shape[index] - xmin;
		else
			shape[index] = shape[index] - ymin;
		index++;
	}
	return shape;
}

int	make_piece(int fd, int shapes)
{
	int *array[26];
	char buf[22];
	char **arr;
	int index = 0;
	
	int	res = 1;
	while (res && index < 26)
	{
		if (*buf)
			ft_bzero(buf, 22);
		res = read(fd, buf, 21);
		if (res < 20)
			break;
		buf[res] = '\0';
		arr = ft_strsplit(buf, '\n');
		array[index] = check_piece(arr);
		ft_strdel(&arr[0]);
		ft_strdel(&arr[1]);
		ft_strdel(&arr[2]);
		ft_strdel(&arr[3]);
		ft_strdel(arr);
		index++;
	}
	int x = 0;
	int y = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 8)
		{
			printf("%d ", array[x][y]);
			y++;
		}
		x++;
		printf ("\n");
	}
	return (0);
}

int	check_valid_board(int fd)
{
	char buf[547];
	int ret;
	int index;
	int shape;

	index = 0;
	ret = read(fd, buf, 546);
	shape = 0;
	buf[ret] = '\0';
	while (buf[index] != '\0' && ret >= 19 && ret <= 545 &&
			((ret - 1) % 21 == 18 || (ret - 1) % 21 == 19))
	{
		if ((buf[index] != '#' && buf[index] != '.' && buf[index] != '\n') ||
			((index - shape) % 5 == 4 && buf[index] != '\n'))
			break;
		if (index % 21 == 20)
		{
			if (buf[index] != '\n')
				break;
			shape++;
		}
		if (buf[index + 1] == '\0')
			return (shape + 1);
		index++; 
	}
	return (0);
}

int main(int argc, char *argv[])
{
/*	int fd;
	int shapes;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	shapes = check_valid_board(fd);
	close(fd);
	if (!shapes)
		return (0);
	fd = open(argv[1], O_RDONLY);
	make_piece(fd, shapes);
*/
	char **board;
	int shape[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	board = (char **) malloc(sizeof(char *) * (5));
	board[0] = ft_strdup(".....");
	board[1] = ft_strdup(".....");
	board[2] = ft_strdup(".....");
	board[3] = ft_strdup(".....");
	board[4] = "\0";
	place_on_board(board, shape, 0, 0, 'A');

	return (0);
}
