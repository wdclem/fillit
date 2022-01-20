/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:38:50 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/20 17:32:38 by ccariou          ###   ########.fr       */
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
int	*coordinate(char piece)
{
	int	x;
	int y;
	int index;
	int	xndex = 0;
	int	yndex = 0;
	int	coord[8];

	x = 0;
	y = 0;
	index = 0;

	while (index < 20)
	{	
		xndex = index;
		yndex = index;
		if (index == "#")
		{
			x = xndex % 5;
			y = yndex % 4;
			//coord[x][y] could make a struc be easier ?
		}
		index++;
	}


char	*make_tetri(char *tetri[4])
{
	/* from the 4 str make one of with one piece
	 * prob need 19 from 0 so 20  */
	char	*piece;
	int		index;

	piece = ft_strnew(20);
	index = 0;
	while (index < 4)
	{
		piece = ft_strjoin(piece, tetri[index]);
		index++;
	}

	return (piece);
}
/*
t_tetri	*create_list(char	*tetri[4])
{
	t_tetri	*node;
	t_tetri	*head;
	int		index;
	char	letter;
*/
	
