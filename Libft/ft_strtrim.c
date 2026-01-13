/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:57:18 by khebert           #+#    #+#             */
/*   Updated: 2025/11/08 20:32:53 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*new_s1;
	int		i;
	int		start;
	int		end;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	new_s1 = malloc(sizeof(char) * (end - start) + 2);
	if (!new_s1)
		return (NULL);
	while (start <= end)
	{
		new_s1[i] = s1[start];
		start++;
		i++;
	}
	new_s1[i] = '\0';
	return (new_s1);
}
