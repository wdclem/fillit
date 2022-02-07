/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thle <thle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:42:33 by ccariou           #+#    #+#             */
/*   Updated: 2022/02/07 17:02:19 by thle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	draw_board(char **board)
{
	int	i;

	i = 0;
	while (board[i])
	{
		ft_putstr(board[i]);
		ft_putchar('\n');
		i++;
	}
}

int	get_intial_dimension(int amount)
{
	int	dimension;

	dimension = 2;
	while (dimension * dimension < amount * 4)
	{
		dimension++;
	}
	return (dimension);
}

void	delete_board(char ***board)
{
	int	i;

	i = 0;
	if (*board)
	{
		while ((*board)[i])
		{
			ft_strdel(&((*board)[i]));
			i++;
		}
		free(*board);
	*board = NULL;
	}
}

char	**generate_board(int dimension)
{
	char	*template;
	char	**board;
	int		i;

	i = 0;
	template = "....................";
	board = (char **) malloc(sizeof(char *) * (dimension + 1));
	if (board)
	{
		while (i < dimension)
		{
			board[i] = ft_strsub(template, 0, dimension);
			i++;
		}
		board[i] = NULL;
		return (board);
	}
	return (0);
}
