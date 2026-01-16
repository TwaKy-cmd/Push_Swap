/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:40:49 by twaky             #+#    #+#             */
/*   Updated: 2026/01/16 17:40:43 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	size_of_stack(t_stack **stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	temp = *stack;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	find_min(t_stack **stack)
{
	int		min;
	t_stack	*temp;

	temp = *stack;
	min = INT_MAX;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

void	ft_three_big_number(t_stack *stack_a, int *big1, int *big2, int *big3)
{
	t_stack	*temp;

	*big1 = INT_MIN;
	*big2 = INT_MIN;
	*big3 = INT_MIN;
	temp = stack_a;
	while (temp)
	{
		if (temp->value > *big1)
		{
			*big3 = *big2;
			*big2 = *big1;
			*big1 = temp->value;
		}
		else if (temp->value > *big2)
		{
			*big3 = *big2;
			*big2 = temp->value;
		}
		else if (temp->value > *big3)
			*big3 = temp->value;
		temp = temp->next;
	}
}

int	find_cible(t_stack **stack_a, int value)
{
	t_stack	*temp_a;
	int		cible;

	temp_a = *stack_a;
	cible = INT_MAX;
	while (temp_a)
	{
		if (temp_a->value > value && temp_a->value < cible)
			cible = temp_a->value;
		temp_a = temp_a->next;
	}
	return (cible);
}

int	find_position(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
