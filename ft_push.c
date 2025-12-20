/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 00:26:31 by khebert           #+#    #+#             */
/*   Updated: 2025/12/21 00:48:25 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    push(t_stack **dst, t_stack **src)
{
    t_stack *temp;
    
    if (!*src)
        return ;
    temp = (*src);
    (*src) = (*dst)->next;
    temp->next = (*dst);
    (*dst) = temp;
}

void    push_pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    write(1, "pa\n", 3);
}

void    push_pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    write(1, "pb\n", 3);
}