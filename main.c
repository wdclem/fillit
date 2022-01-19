/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thle <thle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/19 21:57:40 by thle             ###   ########.fr       */
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

void	remove_letter(char **board, char c)
{
	int x = 0;
	int y = 0;

	while (x < ft_strlen(*board))
	{
		y = 0;
		while (y < ft_strlen(*board))
		{
			if (board[x][y] == c)
				board[x][y] = '.';
			y++;
		}
		x++;
	}
}

void	remove_from_board(char **board, int *shape, int x, int y, char c)
{
	int	index;
	int	pos_x;
	int	pos_y;

	index = 0;
	pos_x = 0;
	pos_y = 0;
	while (index < 8)
	{
		pos_x = shape[index] + x;
		pos_y = shape[index + 1] + y;
		if (pos_x >= ft_strlen(*board) || pos_y >= ft_strlen(*board) || board[pos_x][pos_y] != c)
		{
			break;
		}
		board[pos_x][pos_y] = '.';
		index = index + 2;
	}
}

int	place_on_board(char **board, int *shape, int x, int y, char c)
{
	int	index;
	int	pos_x;
	int	pos_y;

	index = 0;
	pos_x = 0;
	pos_y = 0;
	while (index < 8)
	{
		pos_x = shape[index] + x;
		pos_y = shape[index + 1] + y;
		index = index + 2;
		if (pos_x >= ft_strlen(*board) || pos_y >= ft_strlen(*board) || board[pos_x][pos_y] != '.')
		{
			remove_from_board(board, shape, x, y, c);
			return (0);
		}
		board[pos_x][pos_y] = c;
	}
	return (1);
}

void	draw_board(char **board)
{
	int index = 0;

	while (board[index])
	{
		printf("%s\n", board[index]);
		index++;
	}
}

int	solver(char **board, int shape[][8], int amount, int index)
{
	int x = 0;
	int y = 0;
	int res = 0;
	int go_to = 0;
	char c;
	
	if (index < 0) return 0;
	while (index < amount)
	{
		c = index + 'A';
		go_to = 0;
		x = 0;
		printf("outtest loop is %d %c\n", index, c);
		while (x < ft_strlen(*board))
		{
			y = 0;
			while (y < ft_strlen(*board))
			{
				res = place_on_board(board, shape[index], x, y, c);
				printf("%s%d %d %d%s\n", GREEN, index, x, y, WHITE);
				draw_board(board);
				if (index == amount - 1 && res)
					return 1;
				if (!res && x == 2 && y == 2)
					return (0);
				if (res)
				{
					if (!solver(board, shape, 2, index + 1))
					{
						remove_letter(board, c);
					}
				}
				// printf("%s%d %d %d%s\n", GREEN, index, x, y, WHITE);
				
				printf("\n");
				y++;
			}
			x++;
		}
		index++;
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
	// int x = 0;
	// int y = 0;
	// while (x < 4)
	// {
	// 	y = 0;
	// 	while (y < 8)
	// 	{
	// 		printf("%d ", array[x][y]);
	// 		y++;
	// 	}
	// 	x++;
	// 	printf ("\n");
	// }
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
	// int fd;
	// int shapes;

	// if (argc != 2)
	// {
	// 	ft_putstr("usage: ./fillit filename\n");
	// 	return (0);
	// }
	// fd = open(argv[1], O_RDONLY);
	// shapes = check_valid_board(fd);
	// close(fd);
	// if (!shapes)
	// 	return (0);
	// fd = open(argv[1], O_RDONLY);
	// make_piece(fd, shapes);

	char **board;
	
	int shape[2][8] = {{0, 0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 1, 0, 2, 1, 2}};
	int shape_1[8] = {0, 0, 0, 1, 1, 0, 1, 1};
	int shape_2[8] = {0, 0, 0, 1, 0, 2, 1, 2};
	board = (char **) malloc(sizeof(char *) * (4));
	board[0] = ft_strdup("...");
	board[1] = ft_strdup("...");
	board[2] = ft_strdup("...");
	board[3] = NULL;
	solver(board, shape, 2, 0);
	// place_on_board(board, shape[1], 0, 0, 'A');
	// while(*board)
	// {
	// 	printf("%s\n", *board);
	// 	board++;
	// }
	printf("%sIN MAIN%s\n", RED, WHITE);
	draw_board(board);

	return (0);
}