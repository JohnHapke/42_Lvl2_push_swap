/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:05:22 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/15 15:40:52 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_init_stack()
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->value = 0;
    return (stack);
}

t_node  *ft_creat_node(int  num)
{
    t_node  *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    node->nbr = num;
    node->index = 0;
    node->next = NULL;
    return (node);
}

void    ft_add_to_stack(t_stack *stack, int  num)
{
    t_node  *new;
    t_node  *tmp;

    new = ft_creat_node(num);
    if (!new)
        exit(1);
    if (stack->top == NULL)
        stack->top = new;
    else
    {
        tmp = stack->top;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
    stack->value += 1;
}
