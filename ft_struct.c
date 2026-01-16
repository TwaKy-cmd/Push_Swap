/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:48:36 by khebert           #+#    #+#             */
/*   Updated: 2026/01/16 17:40:31 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*ft_last(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	ft_addtoback(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_last(stack);
	last->next = new;
	new->prev = last;
}

t_stack	*ft_middle(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	last = ft_last(stack);
	before_last = *stack;
	while (before_last->next != last)
		before_last = before_last->next;
	return (before_last);
}

int	ft_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}
