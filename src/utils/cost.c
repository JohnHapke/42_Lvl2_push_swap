/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:52:38 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/23 11:41:21 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost_calculation(t_stack *a, t_stack *b, t_best_move *best_move)
{
	t_node		*current;
	int			pos_b;

	best_move->min_cost = MY_INT_MAX;
	pos_b = 0;
	current = b->top;
	while (current != NULL)
	{
		if (ft_total_cost(a, b, pos_b,
				ft_position_a(a, current->index)) < best_move->min_cost)
		{
			best_move->min_cost = ft_total_cost(a, b, pos_b,
					ft_position_a(a, current->index));
			best_move->element_value = current->nbr;
			best_move->best_pos_a = ft_position_a(a, current->index);
			best_move->best_pos_b = pos_b;
		}
		current = current->next;
		pos_b++;
	}
	printf("Best move: pos_b: %d, pos_a: %d, min_cost: %d, value: %d\n", best_move->best_pos_b, best_move->best_pos_a, best_move->min_cost, best_move->element_value);
}

int	ft_total_cost(t_stack *a, t_stack *b, int pos_b, int pos_a)
{
	int	cost_a;
	int	cost_b;
	int	total_cost;

	cost_a = ft_cost_operation(a, pos_a);
	cost_b = ft_cost_operation(b, pos_b);
	total_cost = cost_a + cost_b;
	return (total_cost);
}

int	ft_cost_operation(t_stack *stack, int pos)
{
	if (pos <= stack->size / 2)
		return (pos);
	else
		return (stack->size - pos);
}
