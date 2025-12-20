/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:03:38 by khebert           #+#    #+#             */
/*   Updated: 2025/11/10 12:21:48 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*new_str;
	long	n_long;
	int		len_n;

	n_long = n;
	if (n_long == 0)
		return (ft_strdup("0"));
	if (n_long < 0)
		n_long = -n_long;
	len_n = ft_intlen(n);
	new_str = malloc(sizeof(char) * (len_n + 1));
	if (!new_str)
		return (NULL);
	new_str[len_n] = '\0';
	while (n_long > 0)
	{
		len_n--;
		new_str[len_n] = n_long % 10 + '0';
		n_long /= 10;
	}
	if (n < 0)
		new_str[0] = '-';
	return (new_str);
}

/* int	main(void)
{
	char	*res = ft_itoa(-42);
	int		i = 0;

	while (res[i])
	{
		printf("%c", res[i]);
		i++;
	}
	free(res);
	return (0);
} */