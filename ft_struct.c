/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:48:36 by khebert           #+#    #+#             */
/*   Updated: 2025/12/19 13:53:00 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack *ft_stack_new(int value)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);

    new->value = value;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

t_stack *ft_find_last(t_stack *stack)
{
    t_stack *temp;

    if (!stack)
        return (NULL);
    temp = stack;
    while (temp->next != NULL)
        temp = temp->next;
    return (temp);
}

void    ft_addtoback(t_stack **stack, t_stack *new)
{
    t_stack *last;

    if (!stack || !new)
        return ;
    if (*stack == NULL)
    {
        *stack = new;
        return ;
    }
    last = ft_find_last(*stack);
    last->next = new;
    new->prev = last;
}