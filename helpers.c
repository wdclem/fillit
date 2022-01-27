/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:29:22 by thle              #+#    #+#             */
/*   Updated: 2022/01/26 11:56:45 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//this func needs rewriting since it used printf()
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

int	valid_placement(char **board, int *shape, int x, int y)
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
		if (pos_x >= ft_strlen(*board) || pos_y >= ft_strlen(*board) || board[pos_x][pos_y] != '.')
			return (0);
		index = index + 2;
	}
	return (1);
}
