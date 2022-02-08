/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:24:10 by ccariou           #+#    #+#             */
/*   Updated: 2022/02/08 21:55:02 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	del_struct(t_tetri *tetri, int value)
{
	ft_memdel((void **)(&tetri));
	return (value);
}

static int	make_board(int fd)
{
	t_tetri	*tetri;

	tetri = (t_tetri *) malloc(sizeof(t_tetri));
	tetri->board = NULL;
	tetri->amount = read_board(fd, tetri->tetri);
	if (!(tetri->amount))
		return (del_struct(tetri, 0));
	tetri->board_len = get_intial_dimension(tetri->amount);
	tetri->board = generate_board(tetri->board_len);
	while (!solver(tetri, 0) && tetri->board)
	{
		tetri->board_len++;
		if (tetri->board)
			delete_board(&tetri->board);
		tetri->board = generate_board(tetri->board_len);
	}
	if (!tetri->board)
		return (del_struct(tetri, 0));
	draw_board(tetri->board);
	delete_board(&tetri->board);
	return (del_struct(tetri, 1));
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
