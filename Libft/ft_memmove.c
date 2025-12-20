/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:20:40 by khebert           #+#    #+#             */
/*   Updated: 2025/11/10 11:05:30 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*temp_dst;
	char	*temp_src;

	if (!dst && !src)
		return (NULL);
	temp_dst = (char *) dst;
	temp_src = (char *) src;
	i = 0;
	if (temp_dst > temp_src)
	{
		while (len > 0)
		{
			len--;
			temp_dst[len] = temp_src[len];
		}
	}
	while (i < len)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dst);
}
