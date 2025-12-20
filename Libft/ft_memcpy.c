/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:34:24 by khebert           #+#    #+#             */
/*   Updated: 2025/11/08 01:50:34 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*b;

	i = 0;
	d = (unsigned char *) dest;
	b = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		d[i] = b[i];
		i++;
	}
	return (dest);
}
