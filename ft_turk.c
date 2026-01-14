/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:57:57 by khebert           #+#    #+#             */
/*   Updated: 2026/01/14 02:24:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_take_cible(t_stack **stack_a, t_stack **stack_b, t_turk_data *data)
{
	data->cheapest_value = calculate_the_cost(stack_b, stack_a, 0, 0);
    data->pos_b = find_position(*stack_b, data->cheapest_value);
	if (data->pos_b < size_of_stack(stack_b) / 2)
	{
   		data->cost_b = data->pos_b;
    	data->is_rb = 1;
	}
	else
    {
        data->cost_b = (size_of_stack(stack_b) - data->pos_b);
        data->is_rb = 0;
    }
    data->cible = find_cible(stack_a, data->cheapest_value);
    data->pos_cible = find_position(*stack_a, data->cible);
    if (data->pos_cible < size_of_stack(stack_a) / 2)
    {
        data->cost_a = data->pos_cible;
        data->is_ra = 1;
    }   
    else
    {
        data->cost_a = (size_of_stack(stack_a) - data->pos_cible);
        data->is_ra = 0;
    }
}

void	ft_cost(t_stack **stack_b, t_stack **stack_a, t_turk_data *data)
{
	if (data->is_ra == 1 && data->is_rb == 1)
	{
		while (data->cost_a > 0 && data->cost_b > 0)
		{
			rr(stack_a, stack_b);
			data->cost_a--;
			data->cost_b--;
		}
	}
	if (data->is_ra == 0 && data->is_rb == 0)
	{
		while (data->cost_a > 0 && data->cost_b > 0)
		{
			rrr(stack_a, stack_b);
			data->cost_a--;
			data->cost_b--;
		}
	}
	while (data->cost_a > 0)
	{
		if (data->is_ra)
			ra(stack_a);
		else
			rra(stack_a);
		data->cost_a--;
	}
	while (data->cost_b > 0)
	{
		if (data->is_rb)
			rb(stack_b);
		else
			rrb(stack_b);
		data->cost_b--;
	}
}

void	ft_total_sort(t_stack **stack_a, t_turk_data *data)
{
	data->cheapest_value = find_min(stack_a);
	data->pos_cible = find_position(*stack_a, data->cheapest_value);
	if (data->pos_cible < size_of_stack(stack_a) / 2)
		while (data->pos_cible-- > 0)
			ra(stack_a);
	else
	{
		data->pos_cible = (size_of_stack(stack_a) - data->pos_cible);
		while (data->pos_cible-- > 0)
			rra(stack_a);
	}
}
void    ft_turk_algo(t_stack **stack_a, t_stack **stack_b)
{
	int     	big[3];
	t_turk_data data = {0};  // ← Initialise tout à 0 !

	ft_three_big_number(*stack_a, &big[0], &big[1], &big[2]);
	while (size_of_stack(stack_a) > 3)
	{
		if ((*stack_a)->value == big[0] || 
			(*stack_a)->value == big[1] || 
			(*stack_a)->value == big[2])
			ra(stack_a);
		else
			push_pb(stack_a, stack_b);
	}
	three_args(stack_a);
	while (*stack_b)
	{
		ft_take_cible(stack_a, stack_b, &data);
		ft_cost(stack_a, stack_b, &data);
		push_pa(stack_a, stack_b);
	}
	ft_total_sort(stack_a, &data);
}