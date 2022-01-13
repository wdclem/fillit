/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/13 19:21:13 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //rmb to delete
#include "fillit.h"

char	*map;

void	print;
int	checker(int fd, struct tetris)
{
	int error;
	int
int	main(int argc, char *argv[])
{
	/* two variables to open file, might not need line */
	struct tetri /* to be made, use number of tetri, len, position */
	//char	*testfile;

	/* Check for only one file, switch printf to putstr */
	if (argc != 2)
	{
		printf("Usage only with one arg\n");
		return (1);
	}
	read(argv[1]);
}
struct	*read(char *testfile)
{
	/* might be smarter to put all in a buffer, since its gonna be small files ? */
	char	buffer[maxsize];
	int		fd;
	int		bytes

	fd = open (argv[1], O_RDONLY);
	if (fd == -1 || read(fd,buf, 1) == 0)
	{
		printf("error pas content\n");
		return (1)
	}
	bytes = read(fd, buffer, MAXSIZE);
	close(fd);

	if (!valid(buffer, bytes))
		return (1);\
	return(create list);
}
/* one piece is = 21 char (5 per lines et one extra \n) */
int	valid(char *buffer, int bytes)
{
	int	index;

	index = 0;

	while (index <= bytes)
	{


