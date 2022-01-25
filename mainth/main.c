/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/25 12:23:10 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thle <thle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/21 20:06:57 by thle             ###   ########.fr       */
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

void	draw_board(char **board)
{
	int index = 0;

	while (board[index])
	{
		printf("%s\n", board[index]);
		index++;
	}
	printf("\n");
}

void	remove_from_board(char **board, int *shape, int x, int y)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		board[shape[index] + x][shape[index + 1] + y] = '.';
		index = index + 2;
	}
}

void	place_on_board(char **board, int *shape, int x, int y, char c)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		board[shape[index] + x][shape[index + 1] + y] = c;
		index = index + 2;
	}
}

int	valid_placement(char **board, int *shape, int x, int y)
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
		if (pos_x >= ft_strlen(*board) || pos_y >= ft_strlen(*board) || board[pos_x][pos_y] != '.')
			return (0);
		index = index + 2;
	}
	return (1);
}



int	solver(char **board, int shape[][8], int amount, int index)
{
	int x = 0;
	int y = 0;
	int res = 0;
	char c;

	// if (index == amount) exit(0);
	// printf("%sINDEX IS %d%s\n", MAGENTA, index, WHITE);
	if (index == amount)
		return 1;
	while (index < amount)
	{
		c = index + 'A';
		x = 0;
		// printf("%soutter loop is %d %c\n", BLUE, index, c);
		// draw_board(board);
		// printf("%s", WHITE);
		while (x < ft_strlen(*board))
		{
			y = 0;
			while (y < ft_strlen(*board))
			{
				int res = valid_placement(board, shape[index], x, y);
				if (!res && x == ft_strlen(*board) - 1 && y == ft_strlen(*board) - 1)
					return (0);
				// printf("%sindex:%d%s %s x:%d y:%d placement:%d%s\n", RED, index, WHITE, YELLOW,x,y,res, WHITE);
				if (res)
				{
					// draw_board(board);
					place_on_board(board, shape[index], x, y, c);
					// draw_board(board);
					// printf("%sindex:%d x:%d y:%d%s\n", GREEN, index, x, y, WHITE);
					if (!solver(board, shape, amount, index + 1))
					{
						// printf("removing\n");
						remove_from_board(board, shape[index], x, y);
					}
					else
						return 1;

				}
				// printf("%soutter loop is %d %c\n", BLUE, index, c);
				// draw_board(board);
				printf("%s", WHITE);
				y++;
			}
			x++;
		}
		index++;
	}
	return (0);
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
	int fd;
	int shape;

	if (argc != 2)
	{
	ft_putstr("usage: ./fillit filename\n");
	return (0);
	}
	fd = open(argv[1], O_RDONLY);
	shape = check_valid_board(fd);
	close(fd);
	if (!shape)
	return (0);
	fd = open(argv[1], O_RDONLY);
	make_piece(fd, shape);

	char **board;
	int res = solver(board, shape, 8, 0);
	printf("%d\n", res);
	printf("\n%sIN MAIN%s\n", RED, WHITE);
	draw_board(board);
/*
	int shape[8][8] = {{0,0,1,0,2,0,3,0}, {0,0,0,1,0,2,0,3}, {0,0,0,1,0,2,1,2}, {0,1,0,2,1,0,1,1}, {0,0,0,1,1,0,1,1}, {0,0,0,1,1,1,1,2}, {0,0,0,1,1,1,2,1}, {0,0,0,1,0,2,1,1}};
	board = (char **) malloc(sizeof(char *) * (8));
	board[0] = ft_strdup("......");
	board[1] = ft_strdup("......");
	board[2] = ft_strdup("......");
	board[3] = ft_strdup("......");
	board[4] = ft_strdup("......");
	board[5] = ft_strdup("......");
	board[6] = NULL;
	int res = solver(board, shape, 8, 0);
	printf("%d\n", res);
	printf("\n%sIN MAIN%s\n", RED, WHITE);
	draw_board(board);

	//BELOW SHOULD NOT WORK
	// int shape[8][8] = {{0,0,1,0,2,0,3,0}, {0,0,0,1,0,2,0,3}, {0,0,0,1,0,2,1,2}, {0,1,0,2,1,0,1,1}, {0,0,0,1,1,0,1,1}, {0,0,0,1,1,1,1,2}, {0,0,0,1,1,1,2,1}, {0,0,0,1,0,2,1,1}};
	// board = (char **) malloc(sizeof(char *) * (5));
	// board[0] = ft_strdup(".....");
	// board[1] = ft_strdup(".....");
	// board[2] = ft_strdup(".....");
	// board[3] = ft_strdup(".....");
	// board[4] = ft_strdup(".....");
	// board[5] = NULL;
	// int res = solver(board, shape, 8, 0);
	// printf("%d\n", res);
	// printf("\n%sIN MAIN%s\n", RED, WHITE);
	// draw_board(board);

	// int shape[3][8] = {{0,0,0,1,0,2,0,3}, {0,0,0,1,0,2,1,2}, {0,1,0,2,1,0,1,1}};
	// board = (char **) malloc(sizeof(char *) * 5);
	// board[0] = ft_strdup("....");
	// board[1] = ft_strdup("....");
	// board[2] = ft_strdup("....");
	// board[3] = ft_strdup("....");
	// board[4] = NULL;
	// solver(board, shape, 3, 0);
	// printf("\n%sIN MAIN%s\n", RED, WHITE);
	// draw_board(board);

	//BELOW SHOULD NOT WORK
	// int shape[3][8] = {{0,0,0,1,0,2,0,3}, {0,0,0,1,0,2,1,2}, {0,1,1,1,2,0,2,1}};
	// board = (char **) malloc(sizeof(char *) * 4);
	// board[0] = ft_strdup("...");
	// board[1] = ft_strdup("...");
	// board[2] = ft_strdup("...");
	// board[3] = NULL;
	// int res = solver(board, shape, 3, 0);
	// printf("%d\n", res);
	// printf("%sIN MAIN%s\n", RED, WHITE);
	// draw_board(board);




	// int shape[2][8] = {{0, 0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 1, 0, 2, 1, 2}};
	// board = (char **) malloc(sizeof(char *) * (4));
	// board[0] = ft_strdup("...");
	// board[1] = ft_strdup("...");
	// board[2] = ft_strdup("...");
	// board[3] = NULL;
	// solver(board, shape, 2, 0);

	// int shape[2][8] = {{0, 0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 1, 0, 2, 1, 2}};
	// board = (char **) malloc(sizeof(char *) * (4));
	// board[0] = ft_strdup("...");
	// board[1] = ft_strdup("...");
	// board[2] = ft_strdup("...");
	// board[3] = NULL;
	// solver(board, shape, 2, 0);
	// printf("\n%sIN MAIN%s\n", RED, WHITE);
	// draw_board(board);

	//BELOW SHOULD NOT WORK
	// int shape[2][8] = {{0, 0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 1, 0, 2, 1, 2}};
	// board = (char **) malloc(sizeof(char *) * (3));
	// board[0] = ft_strdup("..");
	// board[1] = ft_strdup("..");
	// board[2] = NULL;
	// int res = solver(board, shape, 2, 0);
	// printf("%d\n", res);
	// printf("%sIN MAIN%s\n", RED, WHITE);
	// draw_board(board);
*/
	return (0);
}
