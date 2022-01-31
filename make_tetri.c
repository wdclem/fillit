/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:38:50 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/31 09:32:52 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	coordinate(char **piece, int	*tetri)
{
	int	x;
	int y;
	int index;
	int	xmax = 3;
	int	ymax = 3;
	int	count;

	x = 0;
	index = 0;
	count = 0;

		while (x < 4)
		{
			y = 0;
			while (y < 4)
			{
				if (piece[x][y] == '#')
				{
					if (x < xmax)
						xmax = x;
					if (y < ymax)
						ymax = y;
					tetri[index] = x;
					index++;
					tetri[index] = y;
					index++;
				}
				y++;
			}
			x++;
		}
	index = 0;
	while (index < 8)
	{
		if (index % 2 == 0)
			tetri[index] = tetri[index] - xmax;
		else
			tetri[index] = tetri[index] - ymax;
		index++;
	}
}
