/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:28 by thule             #+#    #+#             */
/*   Updated: 2022/02/03 15:55:48 by thule            ###   ########.fr       */
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

typedef struct s_board
{
	char **board;
	int amount;
	int len;
	int x;
	int y;
}				t_board;

//solver.c
int	solver(char **board, int shape[][8], int amount, int index);

//helpers.c
void	draw_board(char **board);
void	removal(char **board, int *shape, int x, int y);
void	placement(char **board, int *shape, int arr[2], char c);
int		valid_placement(char **board, int *shape, int arr[2], char c);
int		get_intial_dimension(int amount);

//check_tetriminos.c
int	read_board(int fd, int arr[26][8]);

//board.c
void	delete_board(char ***board);
char	**generate_board(int dimension);

#endif