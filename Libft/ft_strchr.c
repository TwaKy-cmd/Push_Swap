/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:02:40 by khebert           #+#    #+#             */
/*   Updated: 2025/11/09 23:08:48 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_cast;

	c_cast = c;
	i = 0;
	while (s[i])
	{
		if (c_cast == s[i])
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c_cast)
		return ((char *) &s[i]);
	return (NULL);
}
