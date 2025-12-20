/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khebert <khebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:22:57 by khebert           #+#    #+#             */
/*   Updated: 2025/12/21 00:49:24 by khebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Libft/libft.h"

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
    struct s_stack *prev;
} t_stack;

/* FT_STRUCT.C */

t_stack *ft_stack_new(int value);
t_stack *ft_find_last(t_stack *stack);
void    ft_addtoback(t_stack **stack, t_stack *new);

/* FT_PARSING.C */

t_stack *ft_split_args(char *argv);
t_stack *ft_parse_args(int argc, char *argv[]);
void    ft_print_stack(t_stack *stack);

/* FT_PUSH.C */

void    push(t_stack **dst, t_stack **src);
void    push_pa(t_stack **stack_a, t_stack **stack_b);
void    push_pb(t_stack **stack_a, t_stack **stack_b);

/* FT_REVERSE_ROTATE.C */



/* FT_ROTATE.C */



/* FT_SWAP.C */



#endif