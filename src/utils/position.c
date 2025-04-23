/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:53:50 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/23 11:48:54 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_partition_stack(t_stack *a, t_stack *b)
{
	int		i;
	int		size;

	size = a->size;
	i = 0;
	while (i < (size / 2))
	{
		if (a->top->index <= (size / 2))
		{
			ft_push_handler(a, b, PB);
			a->size--;
			b->size++;
		}
		else
			ft_rotate_handler(a, b, RA);
		i++;
	}
	while (i < (size - 3))
	{
		ft_push_handler(a, b, PB);
		a->size--;
		b->size++;
		i++;
	}
}

int	ft_position_a(t_stack *a, int index_b)
{
	t_node	*current_a;
	int		max_index;
	int		min_index;

	if (a->top == NULL)
		return (0);
	max_index = MY_INT_MIN;
	min_index = MY_INT_MAX;
	current_a = a->top;
	while (current_a != NULL)
	{
		if (current_a->index < min_index)
			min_index = current_a->index;
		if (current_a->index > max_index)
			max_index = current_a->index;
		current_a = current_a->next;
	}
	printf("index_b: %d, min_index: %d, max_index: %d\n", index_b, min_index, max_index);
	if (index_b < min_index)
		return (ft_pos_m_index(a, min_index, 0));
	else if (index_b > max_index)
		return ((ft_pos_m_index(a, max_index, 1)) % a->size);
	else
		return (ft_pos_index(a, index_b));
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

int	ft_pos_index(t_stack *a, int index_b)
{
	t_node	*current;
	int		pos;

	pos = 0;
	current = a->top;
	while (current->next != NULL)
	{
		if (current->index < index_b && index_b < current->next->index)
			return (pos + 1);
		pos++;
		current = current->next;
	}
	printf("index_b: %d, pos: %d\n", index_b, pos);
	if (current->index < index_b && a->top->index < index_b)
		return (0);
	if (a->top->index > index_b)
		return (0);
	return (pos);
}
