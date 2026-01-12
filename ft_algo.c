/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twaky <twaky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:40:49 by twaky             #+#    #+#             */
/*   Updated: 2026/01/12 14:21:01 by twaky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int     size_of_stack(t_stack **stack)
{
    int size;
    t_stack *temp;

    size = 0;
    temp = *stack;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    return (size);
}

int find_min(t_stack **stack)
{
    int min = INT_MAX;
    t_stack *temp;
    
    temp = *stack;
    while (temp)
    {
        if (temp->value < min)
            min = temp->value;
        stack = temp->next;
    }
    return (min);
}

void    ft_three_big_number(t_stack *stack_a, int *big1, int *big2, int *big3)
{
    t_stack *temp;

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
            *big2 = temp->value;
        else if (temp->value > *big3)
            *big3 = temp->value;
        temp = temp->next;
    }
}

int     find_cible(t_stack **stack_a, int value)
{
    t_stack *temp_a;
    int cible;

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

int     cost_a(t_stack *stack_a, int cible)
{
    int pos_cible;
    int size_a;
    
    if (cible == INT_MAX)
        cible = find_min(stack_a);
    pos_cible = find_position(stack_a, cible);
    size_a = size_of_stack(stack_a);
    if (pos_cible < size_a / 2)
        return (pos_cible);
    else
        return (size_a - pos_cible);
}

int     cost_b(t_stack *stack_b, int value)
{
    int pos_b;
    int cost_b;
    int size_b;
    
    pos_b = find_position(stack_b, value);
    size_b = size_of_stack(stack_b);
    if (pos_b < size_b/2)
        cost_b = pos_b;
    else
        cost_b = (size_b - pos_b);
    return (cost_b);
}

int     calculate_the_cost(t_stack **stack_b, t_stack **stack_a, int cost, int cheapest_value)
{
    t_stack *temp_a;
    t_stack *temp_b;
    int     temp_cost;
    int     value;
    int     cible;
    
    temp_b = *stack_b;
    cost = INT_MAX;
    cheapest_value = 0;
    while (temp_b)
    {
        temp_a = *stack_a;
        value = temp_b->value;
        cible = find_cible(stack_a, value);
        temp_cost = cost_b(*stack_b, value);
        temp_cost += cost_a(*stack_a, cible) + 1;
        if (temp_cost < cost)
        {
            cost = temp_cost;
            cheapest_value = value;
        }
        temp_b = temp_b->next;
    }
    return (cheapest_value);
}

void    ft_turk_algo(t_stack **stack_a, t_stack **stack_b)
{
    int     big[3];
    int     cheapest_value;
    int     cost;
    int     cible;
    int     pos_b;
    int     pos_cible;
    
    ft_three_big_number(stack_a, &big[0], &big[1], &big[2]);
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
        cheapest_value = calculate_the_cost(stack_b, stack_a, cost, cheapest_value);
        pos_b = find_position(stack_b, cheapest_value);
        if (pos_b < size_of_stack(stack_b) / 2)
        {
            while (pos_b-- > 0)
                rb(stack_b);
        }
        else
        {
            pos_b = (size_of_stack(stack_b) - pos_b);
            while (pos_b-- > 0)
                rrb(stack_b);
        }
        cible = find_cible(stack_a, cheapest_value);
        pos_cible = find_position(*stack_a, cible);
        if (pos_cible < size_of_stack(stack_a) / 2)
            while (pos_cible-- > 0)
                ra(stack_a);
        else
        {
            pos_cible = (size_of_stack(stack_a) - pos_cible);
            while (pos_cible-- > 0)
                rra(stack_a);
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

    /* ordre : 
    - Prendre les 3 plus grand nombre de a et les garder dans a mettre le reste a b
    - Trier les 3 gros nombre (dans function turk)
    - Calculer pour chaque nombre sont nombre de cout et stocker le minimum
        - En fonction de :
            - sa position dans stack b on calcul le coup
    - Trouver l'emplacement du minimum dans A et y placer le nombre
    - Verifier que A soit bien trier.
    */