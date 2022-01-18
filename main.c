/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/18 09:19:00 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //rmb to delete
#include "fillit.h"

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

int	*check_piece(char **arr)
{
	int x = 0;
	int y = 0;
	int xmin = 3;
	int ymin = 3;
	int counter = 0;
	int index = 0;
	int *shape = (int *) malloc (sizeof(int) * 4);
	
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (arr[x][y] == '#')
			{
				if (x < xmin)
					xmin = x;
				if (y < ymin)
					ymin = y;
				if (x != 0 && arr[x - 1][y] == '#')
					counter++;
				if (x != 3 && arr[x + 1][y] == '#')
					counter++;
				if (y != 0 && arr[x][y - 1] == '#')
					counter++;
				if (y != 3 && arr[x][y + 1] == '#')
					counter++;
				shape[index++] = x;
				shape[index++] = y;
			}
			y++;
		}
		x++;
	}
	index = 0;
	printf("%d %d\n", xmin, ymin);
	while (index < 8)
	{
		if (index % 2 == 0)
			shape[index] = shape[index] - xmin;
		else
			shape[index] = shape[index] - ymin;
		index++;
	}
	printf("%d ", shape[0]);
	printf("%d,", shape[1]);
	printf(" %d ", shape[2]);
	printf("%d,", shape[3]);
	printf(" %d ", shape[4]);
	printf("%d,", shape[5]);
	printf(" %d ", shape[6]);
	printf("%d", shape[7]);
	return NULL;
}

int	make_piece(int fd/*, int shapes*/)
{
	char buf[22];
	read(fd, buf, 21);
	buf[21] = '\0';
	char **arr = ft_strsplit(buf, '\n');
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
	printf("%s\n", arr[2]);
	printf("%s\n", arr[3]);
	check_piece(arr);
	
	//free malloc afterward
	ft_strdel(&arr[0]);
	ft_strdel(&arr[1]);
	ft_strdel(&arr[2]);
	ft_strdel(&arr[3]);
	ft_strdel(arr);

	return (0);
}

int	check_valid_board(int fd)
{
	char buf[547];
	int ret;
	int index;
	int shape;

	index = 0;
	ret = read(fd, buf, 546);
	shape = 0;
	buf[ret] = '\0';
	while (buf[index] != '\0' && ret >= 19 && ret <= 545 &&
			((ret - 1) % 21 == 18 || (ret - 1) % 21 == 19))
	{
		if ((buf[index] != '#' && buf[index] != '.' && buf[index] != '\n') ||
			((index - shape) % 5 == 4 && buf[index] != '\n'))
			break;
		if (index % 21 == 20)
		{
			if (buf[index] != '\n')
				break;
			shape++;
		}
		if (buf[index + 1] == '\0')
			return (shape + 1);
		index++; 
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int fd;
	int shapes;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	shapes = check_valid_board(fd);
	close(fd);
	if (!shapes)
		return (0);
	fd = open(argv[1], O_RDONLY);
	make_piece(fd/*, shapes*/);

	return (0);
}
