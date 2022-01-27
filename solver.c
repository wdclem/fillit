/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:38:45 by thle              #+#    #+#             */
/*   Updated: 2022/01/27 14:18:33 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solver(char **board, int shape[][8], int amount, int index)
{
	int x = 0;
	int y = 0;
	int res = 0;
	char c;

	if (!board)
		return (0);
	if (index == amount) 
		return 1;
	while (index < amount)
	{
		c = index + 'A';
		x = 0;
		while (x < ft_strlen(*board))
		{
			y = 0;
			while (y < ft_strlen(*board))
			{
				res = valid_placement(board, shape[index], x, y);
				if (!res && x == ft_strlen(*board) - 1 && y == ft_strlen(*board) - 1)
					return (0);
				if (res)
				{
					place_on_board(board, shape[index], x, y, c);
					if (!solver(board, shape, amount, index + 1))
						remove_from_board(board, shape[index], x, y);
					else
						return 1;
				}
				y++;
			}
			x++;
		}
		index++;
	}
	return (0);
}