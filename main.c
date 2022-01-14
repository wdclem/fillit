/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/14 12:35:21 by ccariou          ###   ########.fr       */
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
	char	*tetri[26];
	int		tetri_count;
	int		fd;
	struct tetri;/* to be made, use number of tetri, len, position */
	//char	*testfile;

	/* Check for only one file, switch printf to putstr */
	if (argc == 2)
	{
		fd = open (argv[1], O_RDONLY);
		if (fd > 0)
		{
			read_check(fd);

	}
	printf("Usage: ./.fillit filename\n");
}

int	file_check(char *buf)
{
	int	index;
	int	j;

	while(*buf)
	{
		if (*buf != '#' && *buf != '.' && *buf != '\n' && != '\0')
			return (0);

	}
}
int	read_check(int fd)
{
	char	*buf;
	int		bytes;
	
	buf = (char *)malloc(545);
	bytes  = read(fd, buf, 544);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		bytes = read(fd, buf, 544)
	}
	if (file_check == 0)
		return (0); 
	free(str);
	close(fd);
	return (something);

/* one piece is = 21 char (5 per lines et one extra \n) */
int	valid(int fd, char [26], char	*file)
{
	int	index;
	char	*line;
	char	*tetri[4];
	index = 0;

	while (index < 4)
	{
		get_next_line(fd, &line);
		tetri[index++] = line;
	}

####
....
....
....


