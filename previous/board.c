/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:10:47 by ccariou           #+#    #+#             */
/*   Updated: 2022/01/21 17:11:07 by ccariou          ###   ########.fr       */
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

void	remove_letter(char **board, char c)
{
	int x = 0;
	int y = 0;

	while (x < ft_strlen(*board))
	{
		y = 0;
		while (y < ft_strlen(*board))
		{
			if (board[x][y] == c)
				board[x][y] = '.';
			y++;
		}
		x++;
	}
}

void	remove_from_board(char **board, int *shape, int x, int y, char c)
{
	int	index;
	int	pos_x;
	int	pos_y;

	index = 0;
	pos_x = 0;
	pos_y = 0;
	while (index < 8)
	{
		pos_x = shape[index] + x;
		pos_y = shape[index + 1] + y;
		if (pos_x >= ft_strlen(*board) || pos_y >= ft_strlen(*board) || board[pos_x][pos_y] != c)
		{
			break;
		}
		board[pos_x][pos_y] = '.';
		index = index + 2;
	}
}

int	place_on_board(char **board, int *shape, int x, int y, char c)
{
	int	index;
	int	pos_x;
	int	pos_y;

	index = 0;
	pos_x = 0;
	pos_y = 0;
	while (index < 8)
	{
		pos_x = shape[index] + x;
		pos_y = shape[index + 1] + y;
		index = index + 2;
		if (pos_x >= ft_strlen(*board) || pos_y >= ft_strlen(*board) || board[pos_x][pos_y] != '.')
		{
			remove_from_board(board, shape, x, y, c);
			return (0);
		}
		board[pos_x][pos_y] = c;
	}
	return (1);
}

void	draw_board(char **board)
{
	int index = 0;

	while (board[index])
	{
		printf("%s\n", board[index]);
		index++;
	}
}

int	solver(char **board, int shape[][8], int amount, int index)
{
	int x = 0;
	int y = 0;
	int res = 0;
	int go_to = 0;
	char c;
	
	if (index < 0) return 0;
	while (index < amount)
	{
		c = index + 'A';
		go_to = 0;
		x = 0;
		printf("outtest loop is %d %c\n", index, c);
		while (x < ft_strlen(*board))
		{
			y = 0;
			while (y < ft_strlen(*board))
			{
				res = place_on_board(board, shape[index], x, y, c);
				printf("%s%d %d %d%s\n", GREEN, index, x, y, WHITE);
				draw_board(board);
				if (index == amount - 1 && res)
					return 1;
				if (!res && x == 2 && y == 2)
					return (0);
				if (res)
				{
					if (!solver(board, shape, 2, index + 1))
					{
						remove_letter(board, c);
					}
				}
				// printf("%s%d %d %d%s\n", GREEN, index, x, y, WHITE);
				
				printf("\n");
				y++;
			}
			x++;
		}
		index++;
	}
	return (1);
}
