/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:35:21 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/17 12:44:49 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// implementation of a handler would be good with a flag to do rr, ra or rb
void	ft_rotate_a(t_stack *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	last = stack_a->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	stack_a->top = stack_a->top->next;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	last = stack_b->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	stack_b->top = stack_b->top->next;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	last = stack_a->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	stack_a->top = stack_a->top->next;
	first->next = NULL;
	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	last = stack_b->top;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	stack_b->top = stack_b->top->next;
	first->next = NULL;
	write(1, "rr\n", 3);
}
