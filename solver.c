/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:30:27 by ccariou           #+#    #+#             */
/*   Updated: 2022/02/08 21:57:27 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "fillit.h"

static void	place_tetri(t_tetri *tetri, int x, int y, int i)
{
	int		j;
	char	c;

	j = 0;
	c = i + 'A';
	while (j < 8)
	{
		tetri->board[x + tetri->tetri[i][j]][y + tetri->tetri[i][j + 1]] = c;
		j = j + 2;
	}
}

static void	remove_tetri(t_tetri *tetri, int x, int y, int i)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		tetri->board[x + tetri->tetri[i][j]][y + tetri->tetri[i][j + 1]] = '.';
		j = j + 2;
	}
}

static int	valid_placment(t_tetri *tetri, int x, int y, int i)
{
	int	j;
	int	pos_x;
	int	pos_y;

	j = 0;
	pos_x = 0;
	pos_y = 0;
	while (j < 8)
	{
		pos_x = tetri->tetri[i][j] + x;
		pos_y = tetri->tetri[i][j + 1] + y;
		if (pos_x < 0 || pos_y < 0 || pos_x >= tetri->board_len
			|| pos_y >= tetri->board_len
			|| tetri->board[pos_x][pos_y] != '.')
			return (0);
		j = j + 2;
	}
	place_tetri(tetri, x, y, i);
	return (1);
}

static int	recursion(t_tetri *tetri, int i)
{
	int	x;
	int	y;

	x = 0;
	while (x < tetri->board_len)
	{
		y = 0;
		while (y < tetri->board_len)
		{
			if (valid_placment(tetri, x, y, i))
			{
				if (solver(tetri, i + 1))
					return (1);
				else
					remove_tetri(tetri, x, y, i);
			}
			else
				if (x == tetri->board_len - 1 && y == tetri->board_len - 1)
					return (0);
			y++;
		}
		x++;
	}
	return (2);
}

int	solver(t_tetri *tetri, int i)
{
	int	res;

	res = 0;
	if (!(tetri->board))
		return (0);
	if (i == tetri->amount)
		return (1);
	while (i < tetri->amount)
	{
		res = recursion(tetri, i);
		if (res == 0 || res == 1)
			return (res);
		i++;
	}
	return (0);
}
