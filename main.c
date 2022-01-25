/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thle <thle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/25 18:57:01 by thle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char *argv[])
{
	int fd;
	int shapes;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	printf("\nin main %d", read_board(fd));
	// shapes = check_valid_board(fd);
	// close(fd);
	// if (!shapes)
	// 	return (0);
	// fd = open(argv[1], O_RDONLY);
	// make_piece(fd, shapes);

	// char **board;
	
	// int shape[8][8] = {{0,0,1,0,2,0,3,0}, {0,0,0,1,0,2,0,3}, {0,0,0,1,0,2,1,2}, {0,1,0,2,1,0,1,1}, {0,0,0,1,1,0,1,1}, {0,0,0,1,1,1,1,2}, {0,0,0,1,1,1,2,1}, {0,0,0,1,0,2,1,1}};
	// board = (char **) malloc(sizeof(char *) * (8));
	// board[0] = ft_strdup("......");
	// board[1] = ft_strdup("......");
	// board[2] = ft_strdup("......");
	// board[3] = ft_strdup("......");
	// board[4] = ft_strdup("......");
	// board[5] = ft_strdup("......");
	// board[6] = NULL;
	// int res = solver(board, shape, 8, 0);
	// printf("%d\n", res);
	// printf("\n%sIN MAIN%s\n", RED, WHITE);
	// draw_board(board);

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
	
	return (0);
}