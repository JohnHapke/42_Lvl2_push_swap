/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:32:27 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/18 12:44:11 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_handler(t_stack *a, t_stack *b)
{
	ft_partition_stack(a, b);
	ft_sort_three(a);
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
