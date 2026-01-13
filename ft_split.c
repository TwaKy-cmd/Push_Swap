/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:18:11 by khebert           #+#    #+#             */
/*   Updated: 2026/01/13 23:18:27 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	count_word(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] != sep && str[i])
				i++;
		}
	}
	return (count);
}

void	write_word(char *dst, char const *str_base, int len, int start)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = str_base[start + i];
		i++;
	}
	dst[i] = '\0';
}

char	**alloc_check(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

int	sep_check(char const *s, char c, int i)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	tab = alloc_check(s, c);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		i = sep_check(s, c, i);
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
		{
			tab[k] = malloc(sizeof(char) * (j + 1));
			write_word(tab[k++], s, j, i);
			i = i + j;
		}
	}
	tab[k] = NULL;
	return (tab);
}