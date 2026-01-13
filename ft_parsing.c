/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:48:44 by khebert           #+#    #+#             */
/*   Updated: 2026/01/13 23:10:17 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack *ft_split_args(char *argv)
{
    t_stack *stack_a;
    t_stack *new;
    char **split_res;
    int i;
    int value;

    stack_a = NULL;
    split_res = ft_split(argv, ' ');
    if (!split_res)
        return (NULL);
    i = 0;
    while (split_res[i] != NULL)
    {
        value = ft_atoi(split_res[i]);
        new = ft_stack_new(value);
        ft_addtoback(&stack_a, new);
        i++;
    }
    free (split_res);
    return (stack_a);
}

t_stack *ft_parse_args(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *new;
    int value;
    int i;

    stack_a = NULL;
    if (argc == 2)
        stack_a = ft_split_args(argv[1]);
    else if (argc > 2)
    {
        i = 1;
        while (i < argc)
        {
            value = ft_atoi(argv[i]);
            new = ft_stack_new(value);
            ft_addtoback(&stack_a, new);
            i++;
        }
    }
    return (stack_a);
}

void    ft_print_stack(t_stack *stack)
{
    t_stack *temp;
    int number;

    number = 0;
    if (!stack)
    {
        write(1, "Stack Empty", 11);
        return ;
    }
    temp = stack;
    while (temp)
    {
        number = temp->value;
        ft_putnbr_fd(number, 1);
        write(1, " ", 1);
        temp = temp->next;
    }
}

void free_stack(t_stack **stack)
{
    t_stack *temp;
    
    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    
    if (argc >= 2)
    {
        stack_a = ft_parse_args(argc, argv);
        stack_b = NULL;
        if (is_sorted(stack_a))
            return (0);
        if (argc == 3)
            two_args(&stack_a);
        else if (argc == 4)
            three_args(&stack_a);
        else if (argc == 6)
            five_args(&stack_a, &stack_b);
        else
            ft_turk_algo(&stack_a, &stack_b);
        free_stack(&stack_a);
        if (stack_b)
            free_stack(&stack_b);
    }
    return (0);
}
