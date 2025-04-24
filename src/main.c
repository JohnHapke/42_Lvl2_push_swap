/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:10:48 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/24 12:04:33 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	if (argc >= 2)
	{
		if (!stack_a || !stack_b)
			ft_error_handler(stack_a, stack_b);
		ft_parse_manager(argc, argv, stack_a);
		if (ft_is_sorted(stack_a) == 0)
			return (0);
		if (argc == 3)
			ft_sort_two(stack_a);
		else if (argc == 4)
			ft_sort_three(stack_a);
		else
			ft_sort_handler(stack_a, stack_b);
	}
	else
		ft_error_handler(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
