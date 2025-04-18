/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:18:29 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/18 10:43:06 by jhapke           ###   ########.fr       */
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
	t_node	*tmp;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	tmp = stack->top;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
		{
			ft_swap_handler(stack, NULL, SA);
			tmp = stack->top;
		}
		else
			tmp = tmp->next;
	}
}
