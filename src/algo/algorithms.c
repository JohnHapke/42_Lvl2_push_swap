/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:18:29 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/25 09:02:31 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_algo_handler(t_stack *stack_a, t_stack *stack_b, int argc)
{
	int	min1;
	int	min2;

	min1 = MY_INT_MAX;
	min2 = MY_INT_MAX;
	if (argc == 3)
		ft_sort_two(stack_a);
	else if (argc == 4)
		ft_sort_three(stack_a);
	else if (argc == 6)
		ft_sort_five(stack_a, stack_b, min1, min2);
	else
		ft_sort_handler(stack_a, stack_b);
}

void	ft_sort_two(t_stack *stack)
{
	if (stack->top->nbr > stack->top->next->nbr)
		ft_swap_handler(stack, NULL, SA);
}

void	ft_sort_three(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->top;
	second = first->next;
	third = second->next;
	if (first->index < second->index && second->index < third->index)
		return ;
	else if (first->index > second->index && first->index < third->index)
		ft_swap_handler(stack, NULL, SA);
	else if (first->index > second->index && second->index > third->index)
	{
		ft_swap_handler(stack, NULL, SA);
		ft_reverse_rotate_handler(stack, NULL, RRA);
	}
	else if (first->index < second->index && first->index > third->index)
		ft_reverse_rotate_handler(stack, NULL, RRA);
	else if (first->index < third->index && second->index > third->index)
	{
		ft_swap_handler(stack, NULL, SA);
		ft_rotate_handler(stack, NULL, RA);
	}
	else if (first->index > third->index && second->index < third->index)
		ft_rotate_handler(stack, NULL, RA);
}

void	ft_sort_five(t_stack *a, t_stack *b, int min1, int min2)
{
	t_node	*current;

	current = a->top;
	while (current != NULL)
	{
		if (current->index < min1)
		{
			min2 = min1;
			min1 = current->index;
		}
		else if (current->index < min2)
			min2 = current->index;
		current = current->next;
	}
	while (a->size > 3)
	{
		if (a->top->index == min1 || a->top->index == min2)
			ft_push_handler(a, b, PB);
		else
			ft_rotate_handler(a, NULL, RA);
	}
	ft_sort_three(a);
	while (b->size > 0)
		ft_push_handler(a, b, PA);
	ft_sort_two(a);
}

void	ft_sort_handler(t_stack *a, t_stack *b)
{
	t_best_move	*best_move;

	best_move = ft_calloc(1, sizeof(t_best_move));
	if (!best_move)
		ft_error_handler(a, b);
	ft_partition_stack(a, b);
	ft_sort_three(a);
	while (b->size > 0)
	{
		ft_cost_calculation(a, b, best_move);
		ft_exec_best_move(a, b, best_move);
	}
	while (a->top->index != 0)
		ft_reverse_rotate_handler(a, NULL, RRA);
	free (best_move);
}
