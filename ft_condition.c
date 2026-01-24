/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:12:28 by khebert           #+#    #+#             */
/*   Updated: 2026/01/24 18:45:51 by khebert          ###   ########.fr       */
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

int	is_double(t_stack *stack)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = stack;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->value == temp2->value)
				return (1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (0);
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
