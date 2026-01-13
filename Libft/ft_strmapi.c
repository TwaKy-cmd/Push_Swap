/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:57:30 by khebert           #+#    #+#             */
/*   Updated: 2025/11/08 23:17:28 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len_s;
	unsigned int	i;
	char			*new_s;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	new_s = malloc(sizeof(char) * len_s + 1);
	if (!new_s)
		return (NULL);
	while (i < len_s)
	{
		new_s[i] = (*f)(i, s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
