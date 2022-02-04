/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thle <thle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:29:22 by thle              #+#    #+#             */
/*   Updated: 2022/02/04 13:18:25 by thle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	draw_board(char **board)
{
	int	index;

	index = 0;
	while (board[index])
	{
		ft_putstr(board[index]);
		ft_putchar('\n');
		index++;
	}
}

void	removal(char **board, int *shape, int x, int y)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		board[shape[index] + x][shape[index + 1] + y] = '.';
		index = index + 2;
	}
}

void	placement(char **board, int *shape, int arr[2], char c)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		board[shape[index] + arr[0]][shape[index + 1] + arr[1]] = c;
		index = index + 2;
	}
}

int	valid_placement(char **board, int *shape, int arr[2], char c)
{
	int	index;
	int	pos_x;
	int	pos_y;
	int	len;

	len = ft_strlen(*board);
	index = 0;
	pos_x = 0;
	pos_y = 0;
	while (index < 8)
	{
		pos_x = shape[index] + arr[0];
		pos_y = shape[index + 1] + arr[1];
		if (pos_x >= len || pos_y >= len || board[pos_x][pos_y] != '.')
			return (0);
		index = index + 2;
	}
	placement(board, shape, arr, c);
	return (1);
}

int	get_intial_dimension(int amount)
{
	int	dimension;

	dimension = 2;
	while (dimension * dimension < amount * 4)
	{
		dimension++;
	}
	return (dimension);
}
