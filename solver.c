/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:30:27 by ccariou           #+#    #+#             */
/*   Updated: 2022/02/05 18:53:27 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fillit.h"

static void	remove_tetri(char **board, int *shape, int x, int y)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		board[shape[i] + x][shape[i + 1] + y] = '.';
		i = i + 2;
	}
}

static void	place_tetri(char **board, int *shape, int arr[2], char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		board[shape[i] + arr[0]][shape[i + 1] + arr[1]] = c;
		i = i + 2;
	}
}

/* arr[0] = x; arr[1] = y; arr[2] = dimension */
static int	valid_placement(char **board, int *shape, int arr[3], char c)
{
	int	i;
	int	pos_x;
	int	pos_y;

	i = 0;
	pos_x = 0;
	pos_y = 0;
	while (i < 8)
	{
		pos_x = shape[i] + arr[0];
		pos_y = shape[i + 1] + arr[1];
		if (pos_x >= arr[2] || pos_y >= arr[2] || board[pos_x][pos_y] != '.')
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
					(int [3]){x, y, arr[1]}, i + 'A'))
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

/* arr[0] = amount; arr[1] = dimension/ length */
int	solver(char **board, int tetri[][8], int arr[2], int i)
{
	int	res;

	if (i == arr[0])
		return (1);
	while (i < arr[0])
	{
		res = recursion(board, tetri, arr, i);
		if (res == 0 || res == 1)
			return (res);
		i++;
	}
	return (0);
}
