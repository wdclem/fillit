/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:49:53 by thule             #+#    #+#             */
/*   Updated: 2022/01/26 12:19:54 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	shift_piece(int *coordinate)
{
	int	x;
	int	y;
	int index;

	x = 3;
	y = 3;
	index = 0;
	while (index < 8)
	{
		if (index % 2 == 0 && coordinate[index] < x)
			x = coordinate[index];
		else
			y = coordinate[index];
		index++;
	}
	index = 0;
	while (index < 8)
	{
		if (index % 2 == 0)
			coordinate[index] = coordinate[index] - x;
		else
			coordinate[index] = coordinate[index] - y;
		index++;
	}
}

void	make_piece(char *piece, int *coordinate)
{
	int	index;
	int	pos;
	
	index = 0;
	pos = 0;
	while (piece[index])
	{
		if (piece[index] == '#')
		{
			if (index >= 0 && index <= 3)
				coordinate[pos++] = 0;
			else if (index >= 5 && index <= 8)
				coordinate[pos++] = 1;
			else if (index >= 10 && index <= 13)
				coordinate[pos++] = 2;
			else
				coordinate[pos++] = 3;
			coordinate[pos++] = index % 5;
		}
		index++;
	}
	shift_piece(coordinate);
}

int	check_piece(char *piece)
{
	int index;
	int counter; //either 6 or 8

	index = 0;
	counter = 0;
	while (piece[index])
	{
		if ((piece[index] != '.' && piece[index] != '#' && piece[index] != '\n') ||
			((index % 5 == 4 || index == 20) && piece[index] != '\n'))
			return (0);
		if (piece[index] == '#')
		{
			if (index - 5 >= 0 && piece[index - 5] == '#')
				counter++;
			if (index + 5 <= 18 && piece[index + 5] == '#')
				counter++;
			if (index - 1 >= 0 && piece[index - 1] == '#')
				counter++;
			if (index + 1 <= 18 && piece[index + 1] == '#')
				counter++;
		}
		index++;
	}
	return (counter);
}

int	read_board(int fd, int arr[26][8])
{
	char	buf[22];
	int		ret;
	int		index;
	int		res;

	ret = 1;
	index = 0;
	while (ret)
	{
		ret = read(fd, buf, 21);
		if (ret == 0 && index != 0)
			break;
		buf[ret] = '\0';
		res = check_piece(buf);
		if ((ret < 20 && index == 0) || index >= 26 || (res != 8 && res != 6))
			return (0);
		make_piece(buf, arr[index]);
		index++;
	}
	return (index);
}
