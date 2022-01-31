/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:17:02 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/31 18:40:04 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solver(char **board, int tetri[][8], int amount, int index)
{
	int x = 0;
	int y = 0;
	int res = 0;
	char c;

	if (!board)
		return (0);
	if (index == amount)
		return 1;
	int	count = 0; // TBDELETE
	while (index < amount)
	{
		int len = (int)ft_strlen(*board); // TO CLEAN LATER
		c = index + 'A';
		x = 0;
		while (x < len)
		{
			y = 0;
			while (y < len) 
			{
				int res = valid_placement(board, tetri[index], x, y, len);
				if (!res && x == len - 1 && y == len - 1)
					return (0);
				if (res)
				{
					place_on_board(board, tetri[index], x, y, c);
					if (!solver(board, tetri, amount, index + 1))
					{
						remove_from_board(board, tetri[index], x, y);
					}
					else
						return (1);
				}
				y++;
			}
			x++;
		}
		index++;
	}
	return (0);
}
