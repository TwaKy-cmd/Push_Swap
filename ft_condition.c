/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:12:28 by khebert           #+#    #+#             */
/*   Updated: 2026/01/16 17:26:17 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	two_args(t_stack **stack)
{
	if (!*stack || (*stack)->next == NULL)
		return ;
	if ((*stack)->value > (*stack)->next->value)
		swap_sa(stack);
}

void	three_args(t_stack **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	if (is_sorted(*stack))
		return ;
	if ((*stack)->value > ft_middle(stack)->value)
		swap_sa(stack);
	if ((ft_middle(stack)->value > (*stack)->value)
		&& (ft_middle(stack)->value > ft_last(stack)->value))
	{
		rra(stack);
		if (!is_sorted(*stack))
			swap_sa(stack);
	}
	if (((*stack)->value > ft_middle(stack)->value)
		&& ((*stack)->value < ft_last(stack)->value))
		ra(stack);
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
		while (pos > 0)
		{
			ra(stack_a);
			pos--;
		}
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
