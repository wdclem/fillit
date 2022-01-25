/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:57:46 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/25 15:54:23 by ccariou          ###   ########.fr       */
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

int	ft_solver(char **board, int **tetri, int amount, int index)
{
	int x = 0;
	int y = 0;
	int res = 0;
	char c;

	// if (index == amount) exit(0);
	// printf("%sINDEX IS %d%s\n", MAGENTA, index, WHITE);
	if (index == amount)
		return 1;
	printf("ici dans solver\n");
	while (index < amount)
	{
		c = index + 'A';
		x = 0;
		// printf("%soutter loop is %d %c\n", BLUE, index, c);
		// draw_board(board);
		// printf("%s", WHITE);
		printf("ici dans solver line 100\n");
		while (x < ft_strlen(*board))
		{
			y = 0;
			while (y < ft_strlen(*board))
			{
				int res = valid_placement(board, tetri[index], x, y);
				if (!res && x == ft_strlen(*board) - 1 && y == ft_strlen(*board) - 1)
					return (0);
				// printf("%sindex:%d%s %s x:%d y:%d placement:%d%s\n", RED, index, WHITE, YELLOW,x,y,res, WHITE);
				if (res)
				{
					// draw_board(board);
					place_on_board(board, tetri[index], x, y, c);
					// draw_board(board);
					// printf("%sindex:%d x:%d y:%d%s\n", GREEN, index, x, y, WHITE);
					if (!ft_solver(board, tetri, amount, index + 1))
					{
						// printf("removing\n");
						remove_from_board(board, tetri[index], x, y);
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

int	**check_pieces(int fd, char *argv)
{
	char	*line;
	char	*tetri[4];
	int     index; // navigate in the array
	int		jndex; //navigate through pieces
	int		tetri_numb;
	int		count = 0;
	int		shapes[26][8];

	line = NULL;
	tetri_numb = check_valid_board(fd);
	fd = open(argv, O_RDONLY);
	printf("%d\n", tetri_numb);
	jndex = 0;
	while (jndex < tetri_numb)
	{
		index = 0;
		while (index < 4)
		{
			get_next_line(fd, &line);
			tetri[index++] = line;
		}
		coordinate(tetri, shapes[count]);
		count++;
		/* get the empty line and delete it
		 * or check if can jump over */
		jndex++;
		get_next_line(fd, &line);
	}
	printf("shapes[1] = %d\n", shapes[0][0]);
	printf("shapes[2] = %d\n", shapes[0][1]);
	printf("shapes[1] = %d\n", shapes[0][2]);
	printf("shapes[1] = %d\n", shapes[0][3]);
	printf("shapes[1] = %d\n", shapes[0][4]);
	printf("shapes[1] = %d\n", shapes[0][5]);
	printf("shapes[1] = %d\n", shapes[0][6]);
	printf("shapes[1] = %d\n", shapes[0][7]);
	return (shapes);
}  

int main(int argc, char *argv[])
{
	int		fd;
	int		**tetri;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	tetri = check_pieces(fd, argv[1]);
	close(fd);
	char **board;
	board = (char **) malloc(sizeof(char *) * (7));
	board[0] = ft_strdup("......");
	board[1] = ft_strdup("......");
	board[2] = ft_strdup("......");
	board[3] = ft_strdup("......");
	board[4] = ft_strdup("......");
	board[5] = ft_strdup("......");
	board[6] = NULL;
	int res = ft_solver(board, tetri, 8, 0);
	printf("ici dans main line 231\n");
	printf("%d\n", res);
	printf("\n%sIN MAIN%s\n", RED, WHITE);
	draw_board(board);
	// char *buf = "....\n##..\n.#..\n.#..";

	// if (*buf != '#' && *buf != '.' && *buf != '\n' && *buf != '\0')
	// 	printf("yes");
	// else
	// 	printf("no");

	return (0);
}
