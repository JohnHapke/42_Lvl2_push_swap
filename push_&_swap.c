/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_&_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:24:14 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/17 11:43:24 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (!stack_a || !stack_b || !stack_b->top)
		return ;
	tmp = stack_b->top;
	tmp->next = stack_a->top;
	stack_a->top = tmp;
	stack_b->top = stack_b->top->next;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (!stack_b || !stack_a || !stack_a->top)
		return ;
	tmp = stack_a->top;
	tmp->next = stack_b->top;
	stack_b->top = tmp;
	stack_a->top = stack_a->top->next;
	write(1, "pb\n", 3);
}

void	ft_swap_a(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	second = stack_a->top->next;
	first->next = second->next;
	second->next = first;
	stack_a->top = second;
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	second = stack_b->top->next;
	first->next = second->next;
	second->next = first;
	stack_b->top = second;
	write(1, "sb\n", 3);
}

void	ft_swap_s(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	first = stack_a->top;
	second = stack_a->top->next;
	first->next = second->next;
	second->next = first;
	stack_a->top = second;
	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	first = stack_b->top;
	second = stack_b->top->next;
	first->next = second->next;
	second->next = first;
	stack_b->top = second;
	write(1, "ss\n", 3);
}
