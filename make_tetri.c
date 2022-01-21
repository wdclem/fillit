/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:38:50 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/21 17:09:21 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> /* to delete */
#include "fillit.h"

/*
int	is_valid(char	*piece)
{
	* need to verify if the tetri is valid
	 * check size
	 * check if adjacent
	 * position //
	int	index;
	int	x;
	int y;
	int	xmax;
	int	ymax;
	int count;

	x = 0;
	y = 0;
	xmax = 0;
	ymax = 0;
	count = 0;
	
	return(1);
}
*/
int	*coordinate(char **piece)
{
	int	x;
	int y;
	int index;
	int	xmax = 3;
	int	ymax = 3;
	int	count;
	int	*tetri;

	x = 0;
	index = 0;
	count = 0;
	tetri = (int *) malloc (sizeof(int) * 8);

		while (x < 4)
		{
			y = 0;
			while (y < 4)
			{
				if (piece[x][y] == '#')
				{
					if (x < xmin)
						xmin = x;
					if (y < ymin)
						ymin = y;
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
	return (tetri);
}

/*
char	*make_tetri(char *tetri[4])
{
	* from the 4 str make one of with one piece
	 * prob need 19 from 0 so 20  *
	char	*piece;
	int		index;

	piece = ft_strnew(20);
	index = 0;
	while (index < 4)
	{
		piece = ft_strjoin(piece, tetri[index]);
		index++;
	}
	coordinate(piece);
	return (piece);
}
*/
/*
t_tetri	*create_list(char	*tetri[4])
{
	t_tetri	*node;
	t_tetri	*head;
	int		index;
	char	letter;
*/
	
