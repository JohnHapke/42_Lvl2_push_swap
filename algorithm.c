/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:18:29 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/17 11:30:07 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack *stack)
{
	if (stack->top->nbr > stack->top->next->nbr)
		ft_swap_a(stack);
}

void	ft_sort_three(t_stack *stack)
{
	
}