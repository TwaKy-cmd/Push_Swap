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