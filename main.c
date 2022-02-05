/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:24:10 by ccariou           #+#    #+#             */
/*   Updated: 2022/02/05 18:37:50 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	make_board(int fd)
{
	int		tetri[26][8];
	char	**board;
	int		amount;
	int		dimension;

	board = NULL;
	amount = read_board(fd, tetri);
	if (!amount)
		return (0);
	dimension = get_intial_dimension(amount);
	board = generate_board(dimension);
	if (!board)
		return (0);
	while (!solver(board, tetri, (int [2]){amount, dimension}, 0))
	{
		dimension++;
		if (board)
			delete_board(&board);
		board = generate_board(dimension);
	}
	draw_board(board);
	delete_board(&board);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	fd;

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
	if (!make_board(fd))
		ft_putstr("error\n");
	close(fd);
	return (0);
}
