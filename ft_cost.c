/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:01:14 by khebert           #+#    #+#             */
/*   Updated: 2026/01/16 17:31:27 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	cost_a(t_stack *stack_a, int cible)
{
	int	pos_cible;
	int	size_a;

	if (cible == INT_MAX)
		cible = find_min(&stack_a);
	pos_cible = find_position(stack_a, cible);
	size_a = size_of_stack(&stack_a);
	if (pos_cible < size_a / 2)
		return (pos_cible);
	else
		return (size_a - pos_cible);
}

int	cost_b(t_stack *stack_b, int value)
{
	int	pos_b;
	int	cost_b;
	int	size_b;

	pos_b = find_position(stack_b, value);
	size_b = size_of_stack(&stack_b);
	if (pos_b < size_b / 2)
		cost_b = pos_b;
	else
		cost_b = (size_b - pos_b);
	return (cost_b);
}

int	calculate_the_cost(t_stack **stack_b, t_stack **stack_a, t_turk_data *data)
{
	t_stack	*temp_b;
	int		temp_cost;
	int		value;
	int		cible;

	temp_b = *stack_b;
	data->cost = INT_MAX;
	data->cheapest_value = 0;
	while (temp_b)
	{
		value = temp_b->value;
		cible = find_cible(stack_a, value);
		if (cible == INT_MAX)
			cible = find_min(stack_a);
		temp_cost = cost_b(*stack_b, value);
		temp_cost += cost_a(*stack_a, cible) + 1;
		if (temp_cost < data->cost)
		{
			data->cost = temp_cost;
			data->cheapest_value = value;
		}
		temp_b = temp_b->next;
	}
	return (data->cheapest_value);
}
