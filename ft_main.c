/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:22:09 by khebert           #+#    #+#             */
/*   Updated: 2026/01/16 17:52:18 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc >= 2)
	{
		stack_a = ft_parse_args(argc, argv);
		stack_b = NULL;
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
