/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:22:40 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/31 11:22:59 by ccariou          ###   ########.fr       */
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
