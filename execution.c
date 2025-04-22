/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 08:48:00 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/22 10:12:28 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_best_move(t_stack *a, t_stack *b, t_best_move *best_move)
{
	int		rotate_up_a;
	int		rotate_up_b;
	int		rot_count_a;
	int		rot_count_b;

	rot_count_a = ft_rot_count(a->size, best_move->best_pos_a);
	rot_count_b = ft_rot_count(b->size, best_move->best_pos_b);
	rotate_up_a = ft_rot_up(a->size, best_move->best_pos_a);
	rotate_up_b = ft_rot_up(b->size, best_move->best_pos_b);
	while (rot_count_a > 0 && rot_count_b > 0)
	{
		if (rotate_up_a && rotate_up_b)
			ft_rotate_handler(a, b, RR);
		else if (!rotate_up_a && !rotate_up_b)
			ft_rotate_handler(a, b, RRR);
		else
			break ;
		rot_count_a--;
		rot_count_b--;
	}
	if (rot_count_a > 0)
		ft_rot_exec(a, rot_count_a, rotate_up_a, 0);
	if (rot_count_b > 0)
		ft_rot_exec(b, rot_count_b, rotate_up_b, 1);
	ft_push_handler(a, b, PA);
}

void	ft_rot_exec(t_stack *stack, int rot_count, int rotate_up, int code)
{
	if (code == 0)
	{
		while (rot_count > 0)
		{
			if (rotate_up)
				ft_rotate_handler(stack, NULL, RA);
			else
				ft_rotate_handler(stack, NULL, RRA);
			rot_count--;
		}
	}
	if (code == 1)
	{
		while (rot_count > 0)
		{
			if (rotate_up)
				ft_rotate_handler(NULL, stack, RB);
			else
				ft_rotate_handler(NULL, stack, RRB);
			rot_count--;
		}
	}
}

int	ft_rot_count(int size, int pos)
{
	int	rot;

	if (pos <= (size / 2))
		rot = pos;
	else
		rot = size - pos;
	return (rot);
}

int	ft_rot_up(int size, int pos)
{
	int	flag;

	flag = 0;
	if (pos <= (size / 2))
		flag = 1;
	return (flag);
}
