/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:22:09 by khebert           #+#    #+#             */
/*   Updated: 2026/01/24 16:58:21 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	verificate_errors(char **argv, t_stack *stack_a)
{
	int		i;
	long	nb;

	i = 0;
	if (is_valid_number(argv[i]) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&stack_a);
		return (1);
	}
	nb = ft_atoi(argv[i]);
	if (nb == LONG_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&stack_a);
		return (1);
	}
	if (is_double(stack_a) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&stack_a);
		return (1);
	}
	return (0);
}

int	check_errors(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (verificate_errors(argv, stack_a) == 1)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc >= 2)
	{
		stack_a = ft_parse_args(argc, argv);
		stack_b = NULL;
		if (check_errors(argc, argv, stack_a) == 1)
			exit(1);
		if (is_sorted(stack_a))
			return (0);
		if (argc == 3)
			two_args(&stack_a);
		else if (argc == 4)
			three_args(&stack_a);
		else if (argc == 6)
			five_args(&stack_a, &stack_b);
		else
			ft_turk_algo(&stack_a, &stack_b);
		free_stack(&stack_a);
		if (stack_b)
			free_stack(&stack_b);
	}
	return (0);
}
