/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:10:48 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/15 15:14:01 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

    if (argc > 2)
    {
	    stack_a = ft_init_stack();
	    stack_b = ft_init_stack();
	    if (!stack_a || !stack_b)
            exit(1);
		ft_parse_manager(argc, argv, stack_a);
    }
}