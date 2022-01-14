/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:42:28 by thule             #+#    #+#             */
/*   Updated: 2022/01/14 10:45:49 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H

typedef struct s_tetris
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_tetris;

# include <fcntl.h>
# include "libft/libft.h"



#endif