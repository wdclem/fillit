/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thle <thle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:57:32 by thule             #+#    #+#             */
/*   Updated: 2022/02/04 14:25:32 by thle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_board(char ***board)
{
	int index;

	index = 0;
	while ((*board)[index])
	{
		ft_bzero(&((*board)[index]), ft_strlen((*board)[index]));
		ft_strdel(&((*board)[index]));
		index++;
	}
	free(*board);
	*board = NULL;
}

char	**generate_board(int dimension)
{
	char *template;
	char **board;
	int index;
	
	index = 0;
	template = ".................................................";
	board = (char **) malloc(sizeof(char *) * (dimension + 1));
	while (index < dimension)
	{
		board[index] = ft_strsub(template, 0, dimension);
		index++;
	}
	board[index] = NULL;
	return (board);
}
