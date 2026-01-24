/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:45:22 by khebert           #+#    #+#             */
/*   Updated: 2026/01/24 18:53:08 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pos_five_args(t_stack **stack_a, int pos)
{
	if (pos <= size_of_stack(stack_a) / 2)
	{
		while (pos > 0)
		{
			ra(stack_a);
			pos--;
		}
	}
	else
	{
		while (pos < size_of_stack(stack_a))
		{
			rra(stack_a);
			pos++;
		}
	}
}

void	five_args(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	i;
	int	pos;

	i = 0;
	while (i != 2)
	{
		min = ft_min(*stack_a);
		pos = find_position(*stack_a, min);
		pos_five_args(stack_a, pos);
		push_pb(stack_a, stack_b);
		i++;
	}
	if (i == 2)
	{
		three_args(stack_a);
		push_pa(stack_a, stack_b);
		push_pa(stack_a, stack_b);
	}
}
