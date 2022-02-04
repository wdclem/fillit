/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:24:10 by ccariou           #+#    #+#             */
/*   Updated: 2022/02/04 17:35:04 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_file(int argc, char argv[1], int tetri[][8])
{
	int	fd;
	int	amount;

	if(argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return(0);
	}
	fd = open(&argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error\n");
		return (1);
	}
	amount = read_board(fd, tetri);
	if (!amount)
	{
		ft_putstr("error\n");
		return (1);
	}
	close(fd);
	return (amount);
}

int	main(int argc, char *argv[])
{
	int		amount;
	int		dimension;
	int		tetri[26][8];
	char	**board;

	board = NULL;
	amount = check_file(argc, argv[1], tetri);
	dimension = get_intial_dimension(amount);
	board = generate_board(dimension++);
	while (!solver(board, tetri, (int[2]){amount, dimension}, 0))
	{
		if (board)
			delete_board(&board);
		board = generate_board(dimension);
		dimension++;
	}
	draw_board(board);
	delete_board(&board);
	return (0);
}
