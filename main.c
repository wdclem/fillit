/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/14 12:30:45 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //rmb to delete
#include "fillit.h"

int	check_valid_board(int fd)
{
	// possible max 544;
	char buf[546];
	int ret = read(fd, buf, 545);
	if (ret > 544)
		return (0);
	int shape = (ret + 2) / 21;
	printf("%d", shape);

	return (1);
}

int	main(int argc, char *argv[])
{
	int fd;
	
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit filename\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	check_valid_board(fd);
	

	close(fd);
	
	return (0);
}