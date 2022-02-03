/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:38:45 by thle              #+#    #+#             */
/*   Updated: 2022/02/03 15:40:01 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solver(char **board, int shape[][8], int amount, int index)
{
	int	x;
	int	y;
	int	len;

	len = ft_strlen(*board);
	if (index == amount)
		return (1);
	while (index < amount)
	{
		x = 0;
		while (x < len)
		{
			y = 0;
			while (y < len)
			{
				if (valid_placement(board, shape[index], (int [2]){x, y}, index + 'A'))
					if (solver(board, shape, amount, index + 1))
						return (1);
					else
						removal(board, shape[index], x, y);
				else
					if (x == len - 1 && y == len - 1)
						return (0);
				y++;
			}
			x++;
		}
		index++;
	}
	return (0);
}
