/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:16:06 by khebert           #+#    #+#             */
/*   Updated: 2025/11/09 23:10:06 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	if (len == 0 && !haystack)
		return ((char *) needle);
	if (needle[0] == '\0')
		return ((char *) haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		k = 0;
		while ((i + k) < len && haystack[i + k] == needle[k])
		{
			k++;
			if (needle[k] == '\0')
				return ((char *) haystack + i);
		}
		i++;
	}
	return (NULL);
}
