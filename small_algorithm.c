/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:18:29 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/22 11:54:52 by jhapke           ###   ########.fr       */
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
