/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:09:29 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/24 09:39:56 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_handler(t_stack *stack_a, t_stack *stack_b)
{
	ft_free_stack(stack_a);
	if (stack_b)
		ft_free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
