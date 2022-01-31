/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:34:11 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/31 18:36:36 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int	valid_placement(char **board, int *shape, int x, int y, int len)
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
		if (pos_x >= len || pos_y >= len || board[pos_x][pos_y] != '.')
			return (0);
		index = index + 2;
	}
	return (1);
}
