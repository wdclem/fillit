/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/18 11:10:56 by thule            ###   ########.fr       */
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
	// printf("%c %c %c %c\n", arr[0][0], arr[1][0], arr[2][0], arr[3][0]);
	// printf("%c %c %c %c\n", arr[0][1], arr[1][1], arr[2][1], arr[3][1]);
	// printf("%c %c %c %c\n", arr[0][2], arr[1][2], arr[2][2], arr[3][2]);
	// printf("%c %c %c %c\n\n", arr[0][3], arr[1][3], arr[2][3], arr[3][3]);
	
	// printf("%s\n%s\n%s\n%s\n", arr[0], arr[1], arr[2], arr[3]);
	// printf("%zu", ft_strlen(arr[0]));
	// printf("%c\n", arr[1][3]);
	int x = 0;
	int y = 0;
	int xmin = 3;
	int ymin = 3;
	int counter = 0;
	int index = 0;
	int *shape = (int *) malloc (sizeof(int) * 8);

	x = 0;
	y = 0;
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
				shape[index] = x;
				index++;
				shape[index] = y;
				index++;
			}
			y++;
		}
		x++;
	}
	// index = 0;
	// printf("minx: %d\nminy: %d\n", xmin, ymin);
	// printf("%d ", shape[0]);
	// printf("%d,", shape[1]);
	// printf(" %d ", shape[2]);
	// printf("%d,", shape[3]);
	// printf(" %d ", shape[4]);
	// printf("%d,", shape[5]);
	// printf(" %d ", shape[6]);
	// printf("%d", shape[7]);
	// printf("\n");
	printf("%d %d\n", xmin, ymin);
	while (index < 8)
	{
		if (index % 2 == 0)
			shape[index] = shape[index] - xmin;
		else
			shape[index] = shape[index] - ymin;
		index++;
	}
	// printf("%d ", shape[0]);
	// printf("%d,", shape[1]);
	// printf(" %d ", shape[2]);
	// printf("%d,", shape[3]);
	// printf(" %d ", shape[4]);
	// printf("%d,", shape[5]);
	// printf(" %d ", shape[6]);
	// printf("%d", shape[7]);
	// printf("\n\n");
	return shape;
}

int	make_piece(int fd, int shapes)
{
	int *array[26];
	char buf[22];
	char **arr;
	int index = 0;
	
	int	res = 1;
	while (res && index < 26)
	{
		if (*buf)
			ft_bzero(buf, 22);
		res = read(fd, buf, 21);
		if (res < 20)
			break;
		buf[res] = '\0';
		arr = ft_strsplit(buf, '\n');
		array[index] = check_piece(arr);
		ft_strdel(&arr[0]);
		ft_strdel(&arr[1]);
		ft_strdel(&arr[2]);
		ft_strdel(&arr[3]);
		ft_strdel(arr);
		index++;
	}
	int x = 0;
	int y = 0;
	while (x < 8)
	{
		y = 0;
		while (y < 8)
		{
			printf("%d ", array[x][y]);
			y++;
		}
		x++;
		printf ("\n");
	}

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
	make_piece(fd, shapes);

	return (0);
}