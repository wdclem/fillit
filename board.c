/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:57:32 by thule             #+#    #+#             */
/*   Updated: 2022/01/27 14:33:45 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_board(char ***board)
{
	int index;

	index = 0;
	while ((*board)[index])
	{
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
