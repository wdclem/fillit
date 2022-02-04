/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thle <thle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:38:45 by thle              #+#    #+#             */
/*   Updated: 2022/02/04 13:12:55 by thle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	attempt(char **board, int shape[][8], int arr[2], int index)
{
	int	x;
	int	y;

	x = 0;
	while (x < arr[1])
	{
		y = 0;
		while (y < arr[1])
		{
			if (valid_placement(board, shape[index],
					(int [2]){x, y}, index + 'A'))
			{	
				if (solver(board, shape, arr, index + 1))
					return (1);
				else
					removal(board, shape[index], x, y);
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

int	solver(char **board, int shape[][8], int arr[2], int index)
{
	int	res;

	if (index == arr[0])
		return (1);
	while (index < arr[0])
	{
		res = attempt(board, shape, arr, index);
		if (res == 0 || res == 1)
			return (res);
		index++;
	}
	return (0);
}
