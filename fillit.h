/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:28 by thule             #+#    #+#             */
/*   Updated: 2022/02/04 16:25:29 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_board
{
	char	**board;
	int		amount;
	int		len;
	int		x;
	int		y;
}				t_board;

/* reader.c */
int		read_board(int fd, int tetri[26][8]);

/* solver.c */
int		solver(char **board, int tetri[][8], int arr[2], int i);
int		valid_placement(char **board, int *shape, int arr[2], char c);
void	place_tetri(char **board, int *shape, int arr[2], char c);
void	remove_tetri(char **board, int *shape, int x, int y);

/* board.c */
void	draw_board(char **board);
void	delete_board(char ***board);
int		get_intial_dimension(int amount);
char	**generate_board(int dimension);
void	draw_board(char **board);

#endif
