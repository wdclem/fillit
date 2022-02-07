/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thule <thule@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:19:07 by thule             #+#    #+#             */
/*   Updated: 2021/12/06 17:43:19 by thule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;
	char	*str;

	index = 0;
	str = (char *) b;
	while (index < len)
	{
		*str = (char)c;
		index++;
		str++;
	}
	return (b);
}
