/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:57:46 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/19 11:04:31 by ccariou          ###   ########.fr       */
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
	char buf[547];
    int ret;
    int index;
    int shape;

    index = 0;
    ret = read(fd, buf, 546);
    printf("%d", ret);
    if (ret < 19 || ret > 545 || ((ret - 1) % 21 != 18))
        return (0);
    shape = 0;
    buf[ret] = '\0';
    while (buf[index] != '\0')
    {
        if (buf[index] == '#' || buf[index] == '.' || buf[index] == '\n')
        {
            if ((index - shape) % 5 == 4 && buf[index] != '\n')
                return (0);
            if (index % 21 == 20)
            {
                if (buf[index] != '\n')
                    return (0);
                shape++;
            }
        }
        else
            return (0);
        index++;
    }
    return (shape + 1);
}

int check_pieces(int fd,char *piece[26],char *argv)
{
	char    *line;
	char    *tetri[4];
	int     index; // navigate in the array
	int		jndex; //navigate through pieces
	int		tetri_numb;

	line = NULL;
	tetri_numb = check_valid_board(fd);
	fd = open(argv, O_RDONLY);
	printf("%d\n", tetri_numb);
	jndex = 0;
	while (jndex <= tetri_numb)
	{
		index = 0;
		while (index < 4)
		{
			get_next_line(fd, &line);
			printf("%s \n", line);
			tetri[index++] = line;
		}
		piece[jndex] = tetri[index];
		jndex++;
	}
	return (1);
}  

int main(int argc, char *argv[])
{
	char	*piece[26];
	int 	fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	check_pieces(fd, piece, argv[1]);

	close(fd);

	// char *buf = "....\n##..\n.#..\n.#..";

	// if (*buf != '#' && *buf != '.' && *buf != '\n' && *buf != '\0')
	// 	printf("yes");
	// else
	// 	printf("no");

	return (0);
}
