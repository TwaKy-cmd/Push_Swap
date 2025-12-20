/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:28:30 by khebert           #+#    #+#             */
/*   Updated: 2025/11/09 23:09:35 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cast;
	unsigned char	c_cast;
	size_t			i;

	i = 0;
	s_cast = (unsigned char *) s;
	c_cast = (unsigned char) c;
	while (i < n)
	{
		if (s_cast[i] == c_cast)
			return ((void *) &s_cast[i]);
		i++;
	}
	return (0);
}
