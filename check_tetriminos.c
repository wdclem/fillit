/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thle <thle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:49:53 by thule             #+#    #+#             */
/*   Updated: 2022/01/25 19:29:33 by thle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// void	check_piece(char **arr, int *shape)
// {
// 	int x = 0;
// 	int y = 0;
// 	int xmin = 3;
// 	int ymin = 3;
// 	int counter = 0;
// 	int index = 0;
// 	int *shape = (int *) malloc (sizeof(int) * 8);

// 	x = 0;
// 	y = 0;
// 	while (x < 4)
// 	{
// 		y = 0;
// 		while (y < 4)
// 		{
// 			if (arr[x][y] == '#')
// 			{
// 				if (x < xmin)
// 					xmin = x;
// 				if (y < ymin)
// 					ymin = y;
// 				if (x != 0 && arr[x - 1][y] == '#')
// 					counter++;
// 				if (x != 3 && arr[x + 1][y] == '#')
// 					counter++;
// 				if (y != 0 && arr[x][y - 1] == '#')
// 					counter++;
// 				if (y != 3 && arr[x][y + 1] == '#')
// 					counter++;
// 				shape[index] = x;
// 				index++;
// 				shape[index] = y;
// 				index++;
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// 	index = 0;
// 	while (index < 8)
// 	{
// 		if (index % 2 == 0)
// 			shape[index] = shape[index] - xmin;
// 		else
// 			shape[index] = shape[index] - ymin;
// 		index++;
// 	}
// 	return shape;
// }

// int	make_piece(int fd, int shapes)
// {
// 	int array[26][8];
// 	char buf[22];
// 	char **arr;
// 	int index = 0;
	
// 	int	res = 1;
// 	while (res && index < 26)
// 	{
// 		if (*buf)
// 			ft_bzero(buf, 22);
// 		res = read(fd, buf, 21);
// 		if (res < 20)
// 			break;
// 		buf[res] = '\0';
// 		arr = ft_strsplit(buf, '\n');
// 		check_piece(arr, array[index]);
// 		ft_strdel(&arr[0]);
// 		ft_strdel(&arr[1]);
// 		ft_strdel(&arr[2]);
// 		ft_strdel(&arr[3]);
// 		ft_strdel(arr);
// 		index++;
// 	}
// 	return (0);
// }

// int	check_valid_board(int fd)
// {
// 	char buf[547];
// 	int ret;
// 	int index;
// 	int shape;

// 	index = 0;
// 	ret = read(fd, buf, 546);
// 	shape = 0;
// 	buf[ret] = '\0';
// 	while (buf[index] != '\0' && ret >= 19 && ret <= 545 &&
// 			((ret - 1) % 21 == 18 || (ret - 1) % 21 == 19))
// 	{
// 		if ((buf[index] != '#' && buf[index] != '.' && buf[index] != '\n') ||
// 			((index - shape) % 5 == 4 && buf[index] != '\n'))
// 			break;
// 		if (index % 21 == 20)
// 		{
// 			if (buf[index] != '\n')
// 				break;
// 			shape++;
// 		}
// 		if (buf[index + 1] == '\0')
// 			return (shape + 1);
// 		index++; 
// 	}
// 	return (0);
// }

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

int	read_board(int fd)
{
	char	buf[22];
	int		arr[26][8];
	int		ret;
	int		index;
	int		res;

	ret = read(fd, buf, 21);
	buf[ret] = '\0';
	printf("%d ", check_piece(buf));
	make_piece(buf, arr[0]);
	printf("\n");
	printf("%d ", arr[0][0]);
	printf("%d\n", arr[0][1]);
	printf("%d ", arr[0][2]);
	printf("%d\n", arr[0][3]);
	printf("%d ", arr[0][4]);
	printf("%d\n", arr[0][5]);
	printf("%d ", arr[0][6]);
	printf("%d\n", arr[0][7]);

	// ret = 1;
	// index = 0;
	// while (ret)
	// {
	// 	ret = read(fd, buf, 21);
	// 	if (ret == 0 && index != 0)
	// 		break;
	// 	buf[ret] = '\0';
	// 	res = check_piece(buf);
	// 	printf("ret is %d, res is %d\n", ret, res);
	// 	if ((ret < 20 && index == 0) || index >= 26 || (res != 8 && res != 6))
	// 		return (0);
	// 	index++;
	// }
	
	return (1);
}
