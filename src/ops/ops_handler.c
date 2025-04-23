/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:24:14 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/23 08:33:54 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_handler(t_stack *stack_a, t_stack *stack_b, t_ops flag)
{
	t_node	*tmp;

	if (flag == PA)
	{
		if (!stack_a || !stack_b || !stack_b->top)
			return ;
		tmp = stack_b->top;
		stack_b->top = stack_b->top->next;
		tmp->next = stack_a->top;
		stack_a->top = tmp;
		write(1, "pa\n", 3);
	}
	if (flag == PB)
	{
		if (!stack_b || !stack_a || !stack_a->top)
			return ;
		tmp = stack_a->top;
		stack_a->top = stack_a->top->next;
		tmp->next = stack_b->top;
		stack_b->top = tmp;
		write(1, "pb\n", 3);
	}
}

void	ft_swap_handler(t_stack *a, t_stack *b, t_ops flag)
{
	if (flag == SA || flag == SS)
		ft_swap(a);
	if (flag == SB || flag == SS)
		ft_swap(b);
	if (flag == SA)
		write(1, "sa\n", 3);
	if (flag == SB)
		write(1, "sb\n", 3);
	if (flag == SS)
		write(1, "ss\n", 3);
}

void	ft_rotate_handler(t_stack *a, t_stack *b, t_ops flag)
{
	if (flag == RA || flag == RR)
		ft_rotate(a);
	if (flag == RB || flag == RR)
		ft_rotate(b);
	if (flag == RA)
		write(1, "ra\n", 3);
	if (flag == RB)
		write(1, "rb\n", 3);
	if (flag == RR)
		write(1, "rr\n", 3);
}

void	ft_reverse_rotate_handler(t_stack *a, t_stack *b, t_ops flag)
{
	if (flag == RRA || flag == RRR)
		ft_reverse_rotate(a);
	if (flag == RRB || flag == RRR)
		ft_reverse_rotate(b);
	if (flag == RRA)
		write(1, "rra\n", 4);
	if (flag == RRB)
		write(1, "rrb\n", 4);
	if (flag == RRR)
		write(1, "rrr\n", 4);
}
