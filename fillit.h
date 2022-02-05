/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:28 by thule             #+#    #+#             */
/*   Updated: 2022/02/05 18:54:20 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

/* reader.c */
int		read_board(int fd, int tetri[26][8]);

/* solver.c */
int		solver(char **board, int tetri[][8], int arr[2], int i);

/* board.c */
void	draw_board(char **board);
void	delete_board(char ***board);
int		get_intial_dimension(int amount);
char	**generate_board(int dimension);
void	draw_board(char **board);

#endif
