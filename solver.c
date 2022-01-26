/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:17:02 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/26 12:01:26 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solver(char **board, int tetri[][8], int amount, int index)
{
	int x = 0;
	int y = 0;
	int res = 0;
	char c;

	if (index == amount)
		return 1;
	printf("ici dans solver\n");
	while (index < amount)
	{
		c = index + 'A';
		x = 0;
		while (x < ft_strlen(*board))
		{
			y = 0;
			while (y < ft_strlen(*board))
			{
				int res = valid_placement(board, tetri[index], x, y);
				if (!res && x == ft_strlen(*board) - 1 && y == ft_strlen(*board) - 1)
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
