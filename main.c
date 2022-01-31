/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:57:46 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/31 16:34:30 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //rmb to delete
#include "fillit.h"
#include <math.h>

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

int main(int argc, char *argv[])
{
	int		fd;
	int		count;
	int		tetri[26][8];
	char	**board;

	board = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	count = check_valid_board(fd);
	check_pieces(fd, count, tetri, argv[1]);
	double dimension = sqrt(count * 4);
	while (!solver(board, tetri, count, 0))
	{
		printf("%f	", dimension);
		if (board)
			delete_board(&board);
		board = generate_board(dimension);
		dimension++;
	}
	/*
	printf("tetri[00] = %d\n", tetri[0][0]);
	printf("tetri[01] = %d\n", tetri[0][1]);
	printf("tetri[02] = %d\n", tetri[0][2]);
	printf("tetri[03] = %d\n", tetri[0][3]);
	printf("tetri[04] = %d\n", tetri[0][4]);
	printf("tetri[05] = %d\n", tetri[0][5]);
	printf("tetri[06] = %d\n", tetri[0][6]);
	printf("tetri[10] = %d\n", tetri[1][0]);
	printf("tetri[11] = %d\n", tetri[1][1]);
	printf("tetri[12] = %d\n", tetri[1][2]);
	printf("tetri[13] = %d\n", tetri[1][3]);
	printf("tetri[14] = %d\n", tetri[1][4]);
	printf("tetri[15] = %d\n", tetri[1][5]);
	printf("tetri[16] = %d\n", tetri[1][6]);
	printf("ici dans main line 231\n");
	*/
	printf("\n");
	printf("\n%sIN MAIN%s\n", RED, WHITE);
	draw_board(board);
	// char *buf = "....\n##..\n.#..\n.#..";

	// if (*buf != '#' && *buf != '.' && *buf != '\n' && *buf != '\0')
	// 	printf("yes");
	// else
	// 	printf("no");

	return (0);
}
