/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thle <thle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:28 by thule             #+#    #+#             */
/*   Updated: 2022/01/25 17:39:58 by thle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H


#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

# include <fcntl.h>
# include "libft/libft.h"
# include "stdio.h" //rmb to delete

int		solver(char **board, int shape[][8], int amount, int index);
void	draw_board(char **board);
void	remove_from_board(char **board, int *shape, int x, int y);
void	place_on_board(char **board, int *shape, int x, int y, char c);
int		valid_placement(char **board, int *shape, int x, int y);

int	read_board(int fd);
int	check_piece(char *piece);

#endif