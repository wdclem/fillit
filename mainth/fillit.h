/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:28 by thule             #+#    #+#             */
/*   Updated: 2022/01/25 12:22:22 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

typedef struct tetris
{
	char	**position;
	int		width;
	int		height;
	char	value;
}		t_tetris;

char	*make_tetri(char **string);

#endif
