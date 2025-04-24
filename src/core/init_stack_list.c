/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:05:22 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/24 08:54:17 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		ft_error_handler(stack, NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*ft_create_node(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->nbr = num;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	ft_add_to_stack(t_stack *stack, int num)
{
	t_node	*new_node;
	t_node	*tmp;

	new_node = ft_create_node(num);
	if (!new_node)
		ft_error_handler(stack, NULL);
	if (stack->top == NULL)
		stack->top = new_node;
	else
	{
		tmp = stack->top;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	stack->size++;
}

void	ft_assign_index(t_stack *stack)
{
	t_node	*current;
	t_node	*runner;
	int		index;

	current = stack->top;
	if (!current)
		ft_error_handler(stack, NULL);
	while (current != NULL)
	{
		index = 0;
		runner = stack->top;
		if (!runner)
			ft_error_handler(stack, NULL);
		while (runner != NULL)
		{
			if (runner->nbr < current->nbr)
				index++;
			runner = runner->next;
		}
		current->index = index;
		current = current->next;
	}
}
