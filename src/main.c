/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:10:48 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/25 11:26:31 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	if (argc >= 2)
	{
		if (!stack_a || !stack_b)
			ft_error_handler(stack_a, stack_b);
		ft_parse_manager(argc, argv, stack_a);
		if (ft_is_sorted(stack_a) == 0)
			return (0);
		ft_algo_handler(stack_a, stack_b, argc);
	}
	else
		ft_error_handler(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
