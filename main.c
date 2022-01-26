/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:57:46 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/26 17:39:06 by ccariou          ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	int		fd;
	int		count;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	count = check_valid_board(fd);

	int		tetri[count][8];
	/*
	printf("tetri[0] = %d\n", tetri[0][2]);
	printf("tetri[1] = %d\n", tetri[1][2]);
	printf("tetri[2] = %d\n", tetri[2][2]);
	printf("tetri[3] = %d\n", tetri[3][2]);
	printf("tetri[4] = %d\n", tetri[4][2]);
	printf("tetri[0] = %d\n", tetri[0][2]);
	printf("tetri[1] = %d\n", tetri[1][2]);
	printf("tetri[5] = %d\n", tetri[5][2]);
	printf("How many tetri > %d\n", count);
	check_pieces(fd, count, tetri, argv[1]);
	printf("after check_pieces\n");
	printf("tetri[00] = %d\n", tetri[0][0]);
	printf("tetri[01] = %d\n", tetri[0][1]);
	printf("tetri[02] = %d\n", tetri[0][2]);
	printf("tetri[03] = %d\n", tetri[0][3]);
	printf("tetri[04] = %d\n", tetri[0][4]);
	printf("tetri[05] = %d\n", tetri[0][5]);
	printf("tetri[06] = %d\n", tetri[0][6]);
	printf("tetri[07] = %d\n", tetri[0][7]);
	*/
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
	int res = solver(board, tetri, 7, 0);
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
