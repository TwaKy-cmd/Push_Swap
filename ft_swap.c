/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:10:45 by khebert           #+#    #+#             */
/*   Updated: 2025/12/22 18:36:08 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    swap(t_stack **stack_a)
{
    int temp;

    if (!*stack_a || !(*stack_a)->next)
        return ;
    temp = (*stack_a)->value;
    (*stack_a)->value = (*stack_a)->next->value;
    (*stack_a)->next->value = temp;
}

void    swap_sa(t_stack **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void    swap_sb(t_stack **stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

void    swap_ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}