/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twaky <twaky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:24:02 by khebert           #+#    #+#             */
/*   Updated: 2025/11/10 15:42:33 by twaky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c_cast;
	char	*res;

	i = 0;
	res = 0;
	c_cast = (char) c;
	while (s[i])
	{
		if (s[i] == c_cast)
			res = (char *) &s[i];
		i++;
	}
	if (c_cast == '\0')
		return ((char *) &s[i]);
	return (res);
}
/* #include <stdio.h>

int main (void)
{
	char *test = "salutcv";
	int c = 'u';
	char *res = ft_strrchr(test, c);

	printf("%s\n", res);
	return (0);
} */