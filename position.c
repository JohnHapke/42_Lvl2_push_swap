/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:53:50 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/22 12:01:58 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_position_a(t_stack *a, int index_b)
{
	t_node	*current_a;
	int		max_index;
	int		min_index;
	int		pos;

	if (a->top == NULL)
		return (0);
	pos = 0;
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
	if (current->index < index_b && a->top->index < index_b)
		return (0);
	if (a->top->index > index_b)
		return (0);
	return (pos);
}
