/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/02/03 16:00:51 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int	solver_test(char **board, int shape[][8], int amount, int index)
// {
// 	int	x;
// 	int	y;
// 	int	len;

// 	len = ft_strlen(*board);
// 	if (index == amount)
// 		return (1);
// 	while (index < amount)
// 	{
// 		x = 0;
// 		while (x < len)
// 		{
// 			y = 0;
// 			while (y < len)
// 			{
// 				if (valid_placement(board, shape[index], (int [2]){x, y}, index + 'A'))
// 					if (solver(board, shape, amount, index + 1))
// 						return (1);
// 					else
// 						removal(board, shape[index], x, y);
// 				else
// 					if (x == len - 1 && y == len - 1)
// 						return (0);
// 				y++;
// 			}
// 			x++;
// 		}
// 		index++;
// 	}
// 	return (0);
// }

// int	main(int argc, char *argv[])
// {
// 	int fd;
// 	int amount;
// 	int	arr[26][8];

// 	// board = NULL;
// 	if (argc != 2)
// 	{
// 		ft_putstr("usage: ./fillit filename\n");
// 		return (0);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_putstr("error\n");
// 		return (0);
// 	}
// 	amount = read_board(fd, arr);
// 	int dimension = get_intial_dimension(amount);
// 	t_board *board = (t_board *)malloc(sizeof(t_board));
// 	board = generate_board(dimension++);
// 	// while (!solver_test(board, arr, amount, 0))
// 	// {
// 	// 	if (board)
// 	// 		delete_board(&board);
// 	// 	board = generate_board(dimension);
// 	// 	dimension++;
// 	// }
// 	printf("\n");
// 	draw_board(board);
// 	delete_board(&board);
	
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	int fd;
	int amount;
	int	arr[26][8];
	char **board;

	board = NULL;
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
	amount = read_board(fd, arr);
	int dimension = get_intial_dimension(amount);
	
	board = generate_board(dimension++);
	while (!solver_test(board, arr, amount, 0))
	{
		if (board)
			delete_board(&board);
		board = generate_board(dimension);
		dimension++;
	}
	printf("\n");
	draw_board(board);
	delete_board(&board);
	
	return (0);
}