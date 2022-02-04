/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:51:47 by ccariou           #+#    #+#             */
/*   Updated: 2022/02/04 16:29:27 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	shift_piece(int *coordinate)
{
	int	x;
	int	y;
	int	i;

	x = 3;
	y = 3;
	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0 && coordinate[i] < x)
			x = coordinate[i];
		else
			y = coordinate[i];
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0)
			coordinate[i] = coordinate[i] - x;
		else
			coordinate[i] = coordinate[i] - y;
		i++;
	}
}

static void	make_piece(char *piece, int *coordinate)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			if (i >= 0 && i <= 3)
				coordinate[pos++] = 0;
			else if (i >= 5 && i <= 8)
				coordinate[pos++] = 1;
			else if (i >= 10 && i <= 13)
				coordinate[pos++] = 2;
			else
				coordinate[pos++] = 3;
			coordinate[pos++] = i % 5;
		}
		i++;
	}
	shift_piece(coordinate);
}

static int	check_piece(char *piece)
{
	int	i;
	int	counter; /*either 6 or 8*/

	i = 0;
	counter = 0;
	while (piece[i])
	{
		if ((piece[i] != '.' && piece[i] != '#' && piece[i] != '\n')
			|| ((i % 5 == 4 || i == 20) && piece[i] != '\n'))
			return (0);
		if (piece[i] == '#')
		{
			if (i - 5 >= 0 && piece[i - 5] == '#')
				counter++;
			if (i + 5 <= 18 && piece[i + 5] == '#')
				counter++;
			if (i - 1 >= 0 && piece[i - 1] == '#')
				counter++;
			if (i + 1 <= 18 && piece[i + 1] == '#')
				counter++;
		}
		i++;
	}
	return (counter);
}

int	read_board(int fd, int tetri[26][8])
{
	char	buf[22];
	int		ret;
	int		i;
	int		res;

	ret = 1;
	i = 0;
	while (ret)
	{
		ret = read(fd, buf, 21);
		if (ret == 0 && i != 0)
			break ;
		buf[ret] = '\0';
		res = check_piece(buf);
		if ((ret < 20 && i == 0) || i >= 26 || (res != 8 && res != 6))
			return (0);
		make_piece(buf, tetri[i]);
		i++;
	}
	return (i);
}
