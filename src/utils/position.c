/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:53:50 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/24 11:35:07 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_partition_stack(t_stack *a, t_stack *b)
{
	int	i;
	int	size;

	size = a->size;
	i = 0;
	while (i < (size / 2) && (size / 2) > 3)
	{
		if (a->top->index <= (size / 2))
		{
			ft_push_handler(a, b, PB);
			a->size--;
			b->size++;
			i++;
		}
		else
			ft_rotate_handler(a, b, RA);
	}
	while (i < (size - 3))
	{
		ft_push_handler(a, b, PB);
		a->size--;
		b->size++;
		i++;
	}
}

int	ft_position_a(t_stack *a, int index_b, t_best_move *best_move)
{
	t_node	*current;
	t_node	*next_node;

	current = a->top;
	best_move->min_index = current->index;
	best_move->min_pos_a = 0;
	best_move->pos_a = 0;
	while (current != NULL)
	{
		next_node = current->next;
		if (!current->next)
			next_node = a->top;
		if (current->index < best_move->min_index)
		{
			best_move->min_index = current->index;
			best_move->min_pos_a = best_move->pos_a;
		}
		if ((current->index < index_b && index_b < next_node->index)
			|| (current->index > next_node->index && (index_b > current->index
					|| index_b < next_node->index)))
			return ((best_move->pos_a + 1) % a->size);
		best_move->pos_a++;
		current = current->next;
	}
	return ((best_move->min_pos_a + 1) % a->size);
}

int	ft_pos_m_index(t_stack *a, int m_index, int code)
{
	t_node	*current;
	int		pos;

	current = a->top;
	pos = 0;
	while (current != NULL)
	{
		if (code == 0 && current->index == m_index)
			return (pos);
		if (code == 1 && current->index == m_index)
			return (pos + 1);
		pos++;
		current = current->next;
	}
	return (0);
}

int	ft_is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current->next != NULL)
	{
		if (current->nbr > current->next->nbr)
			return (1);
		current = current->next;
	}
	ft_free_stack(stack);
	return (0);
}
