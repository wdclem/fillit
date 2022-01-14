/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/14 14:53:59 by thule            ###   ########.fr       */
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

int check_valid_board(int fd)
{
	// possible max 544;
	char buf[546];
	int ret;
	int index;
	int shape;

	index = 0;
	ret = read(fd, buf, 545);
	printf("%d", ret);
	if (ret < 19 || ret > 544 || ((ret - 1) % 21 != 18))
		return (0);
	// shape = (ret + 2) / 21;
	shape = 0;
	buf[ret] = '\0';
	while (buf[index] != '\0')
	{
		if (buf[index] == '#' || buf[index] == '.' || buf[index] == '\n')
		{
			if ((index - shape) % 5 == 4 && buf[index] != '\n')
				return (0);
			if (index % 21 == 20 && buf[index] == '\n')
			{
				if (buf[index] != '\n')
					return (0);
				shape++;
			}
			if (buf[index] == '\n')
			{
				printf("%s%d%s	", GREEN, index, WHITE);
				printf("\n");
			}
			else
				printf("%d	", index);
		}
		else
			return (0);
		index++; 
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	int res = check_valid_board(fd);
	printf("\nresult is %d\n", res);

	close(fd);

	// char *buf = "....\n##..\n.#..\n.#..";

	// if (*buf != '#' && *buf != '.' && *buf != '\n' && *buf != '\0')
	// 	printf("yes");
	// else
	// 	printf("no");

	return (0);
}