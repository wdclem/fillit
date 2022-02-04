/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:30:27 by ccariou           #+#    #+#             */
/*   Updated: 2022/02/04 16:30:08 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fillit.h"

void	remove_tetri(char **board, int *shape, int x, int y)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		board[shape[i] + x][shape[i + 1] + y] = '.';
		i = i + 2;
	}
}

void	place_tetri(char **board, int *shape, int arr[2], char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		board[shape[i] + arr[0]][shape[i + 1] + arr[1]] = c;
		i = i + 2;
	}
}

int	valid_placement(char **board, int *shape, int arr[2], char c)
{
	int	i;
	int	pos_x;
	int	pos_y;
	int	len;

	len = ft_strlen(*board);
	i = 0;
	pos_x = 0;
	pos_y = 0;
	while (i < 8)
	{
		pos_x = shape[i] + arr[0];
		pos_y = shape[i + 1] + arr[1];
		if (pos_x >= len || pos_y >= len || board[pos_x][pos_y] != '.')
			return (0);
		i = i + 2;
	}
	place_tetri(board, shape, arr, c);
	return (1);
}

static int	recursion(char **board, int tetri[][8], int arr[2], int i)
{
	int	x;
	int	y;

	x = 0;
	while (x < arr[1])
	{
		y = 0;
		while (y < arr[1])
		{
			if (valid_placement(board, tetri[i],
					(int [2]){x, y}, i + 'A'))
			{
				if (solver(board, tetri, arr, i + 1))
					return (1);
				else
					remove_tetri(board, tetri[i], x, y);
			}
			else
				if (x == arr[1] - 1 && y == arr[1] - 1)
					return (0);
			y++;
		}
		x++;
	}
	return (2);
}

int	solver(char **board, int tetri[][8], int arr[2], int i)
{
	int	res;

	if (i == arr[0])
		return (1);
	/*arr[2] = ft_strlen(*board);*/
	while (i < arr[0])
	{
		res = recursion(board, tetri, arr, i);
		if (res == 0 || res == 1)
			return (res);
		i++;
	}
	return (0);
}
