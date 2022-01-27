/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/27 14:34:12 by thule            ###   ########.fr       */
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
		return (0);
	}
	amount = read_board(fd, arr);
	int dimension = 2;
	while (!solver(board, arr, amount, 0))
	{
		printf("%d	", dimension);
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