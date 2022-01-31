/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:35:09 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/31 16:43:35 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_valid_board(int fd)
{
	char	buf[547];
	int		ret;
	int		index;
	int		shape;

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

void	check_pieces(int fd, int count, int tetri[count][8], char *argv)
{
	char	*line;
	char	*piece[4];
	int		index; // navigate in the array
	int		jndex; //navigate through pieces
	int		tndex = 0;
/*
	printf("tetri[0] = %d\n", tetri[0][2]);
	printf("tetri[1] = %d\n", tetri[1][2]);
	printf("tetri[2] = %d\n", tetri[2][2]);
	printf("tetri[3] = %d\n", tetri[3][2]);
	printf("tetri[4] = %d\n", tetri[4][2]);
	printf("tetri[0] = %d\n", tetri[0][2]);
	printf("tetri[1] = %d\n", tetri[1][2]);
	printf("tetri[5] = %d\n", tetri[5][2]);
*/
	line = NULL;
	fd = open(argv, O_RDONLY);
	printf("%d\n", count);
	jndex = 0;
	while (jndex < count)
	{
		index = 0;
		while (index < 4)
		{
			get_next_line(fd, &line);
			piece[index++] = line;
		}
		coordinate(piece, tetri[tndex]);
		tndex++;
		/* get the empty line and delete it
		 ** or check if can jump over */
		jndex++;
		get_next_line(fd, &line);
	}
/*
	printf("tetri[00] = %d\n", tetri[1][0]);
	printf("tetri[01] = %d\n", tetri[1][1]);
	printf("tetri[02] = %d\n", tetri[1][2]);
	printf("tetri[03] = %d\n", tetri[1][3]);
	printf("tetri[04] = %d\n", tetri[1][4]);
	printf("tetri[05] = %d\n", tetri[1][5]);
	printf("tetri[06] = %d\n", tetri[1][6]);
	printf("tetri[07] = %d\n", tetri[1][7]);
*/
}  
