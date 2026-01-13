/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 22:57:57 by khebert           #+#    #+#             */
/*   Updated: 2026/01/13 22:59:17 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    ft_turk_algo(t_stack **stack_a, t_stack **stack_b)
{
    int     big[3];
    int     cheapest_value;
    int     cible;
    int     pos_b;
    int     pos_cible;
    int     cost_a;
    int     cost_b;
    int     is_ra;
    int     is_rb;
    
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
        cheapest_value = calculate_the_cost(stack_b, stack_a, 0, cheapest_value);
        pos_b = find_position(*stack_b, cheapest_value);
        if (pos_b < size_of_stack(stack_b) / 2)
        {
            cost_b = pos_b;
            is_rb = 1;
        }
        else
        {
            cost_b = (size_of_stack(stack_b) - pos_b);
            is_rb = 0;
        }
        cible = find_cible(stack_a, cheapest_value);
        pos_cible = find_position(*stack_a, cible);
        if (pos_cible < size_of_stack(stack_a) / 2)
        {
            cost_a = pos_cible;
            is_ra = 1;
        }   
        else
        {
            cost_a = (size_of_stack(stack_a) - pos_cible);
            is_ra = 0;
        }
        if (is_ra == 1 && is_rb == 1)
        {
            while (cost_a > 0 && cost_b > 0)
            {
                rr(stack_a, stack_b);
                cost_b--;
                cost_a--;
            }
        }
        if (is_ra == 0 && is_rb == 0)
        {
            while (cost_a > 0 && cost_b > 0)
            {
                rrr(stack_a, stack_b);
                cost_b--;
                cost_a--;
            }
        }
        while (cost_a > 0)
        {
            if (is_ra)
                ra(stack_a);
            else
                rra(stack_a);
            cost_a--;
        }
        while (cost_b > 0)
        {
            if (is_rb)
                rb(stack_b);
            else
                rrb(stack_b);
            cost_b--;
        }
        push_pa(stack_a, stack_b);
    } 
    cheapest_value = find_min(stack_a);
    pos_cible = find_position(*stack_a, cheapest_value);
    if (pos_cible < size_of_stack(stack_a) / 2)
        while (pos_cible-- > 0)
            ra(stack_a);
    else
    {
        pos_cible = (size_of_stack(stack_a) - pos_cible);
        while (pos_cible-- > 0)
            rra(stack_a);
    }
}