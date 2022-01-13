/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:23 by thule             #+#    #+#             */
/*   Updated: 2022/01/13 11:03:50 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //rmb to delete
#include "fillit.h"

char	*map;

void	print;

int	main(int argc, char *argv[])
{
	/* two variables to open file, might not need line */
	int 	fd;
	char	*line;

	/* Check for only one file, switch printf to putstr */
	if (argc != 2)
	{
		printf("Usage only with one arg\n");
		return (1);
	}
	/* Use GNL or just put everything in a buffer */
	printf("got c");
	return (0);
}

