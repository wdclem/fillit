/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:28 by thule             #+#    #+#             */
/*   Updated: 2022/01/31 18:36:22 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line.h"

# include <stdio.h> /* TO DELETE */

int		check_valid_board(int fd);
void	check_pieces(int fd, int count, int tetri[count][8], char *argv);

int		solver(char **board, int tetri[][8], int count, int index);

void	coordinate(char **piece, int *tetri);

void	draw_board(char **board);
void	remove_from_board(char **board, int *tetri, int x, int y);
void	place_on_board(char **board, int *tetri, int x, int y, char c);
int		valid_placement(char **board, int *shape, int x, int y, int len);

void	delete_board(char ***board);
char	**generate_board(int dimension);

#endif
