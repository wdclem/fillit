/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thle <thle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/02/04 14:22:14 by thle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		return (1);
	}
	amount = read_board(fd, arr);
	close(fd);
	if (!amount)
	{
		ft_putstr("error\n");
		return (1);
	}
	int dimension = get_intial_dimension(amount);
	
	board = generate_board(dimension++);
	while (!solver(board, arr, (int[2]){amount, dimension}, 0))
	{
		if (board)
			delete_board(&board);
		board = generate_board(dimension);
		dimension++;
	}
	printf("\n");
	draw_board(board);
	delete_board(&board);
	// printf("%s", *board);
	
	return (0);
}