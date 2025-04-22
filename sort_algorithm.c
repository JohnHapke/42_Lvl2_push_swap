/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:32:27 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/22 12:04:45 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free (best_move);
	best_move = NULL;
}

void	ft_partition_stack(t_stack *a, t_stack *b)
{
	int		i;
	int		size;

	b->size = 0;
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
		i++;
	}
}
