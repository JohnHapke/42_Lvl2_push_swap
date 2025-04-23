/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:18:29 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/23 10:56:22 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sort_handler(t_stack *a, t_stack *b)
{
	t_best_move	*best_move;

	printf("hand: a start: %d, b start: %d\n", a->size, b->size);
	best_move = ft_calloc(1, sizeof(t_best_move));
	if (!best_move)
		ft_error_handler(a, b);
	ft_partition_stack(a, b);
	ft_sort_three(a);
	printf("handl: a bef exe: %d, b bef exe: %d\n", a->size, b->size);
	while (b->size > 0)
	{
		ft_cost_calculation(a, b, best_move);
		ft_exec_best_move(a, b, best_move);
		b->size--;
		a->size++;
	}
	printf("hand: a af exe: %d, b af exe: %d\n", a->size, b->size);
	free (best_move);
}
