/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:10:48 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/18 12:22:39 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp != NULL)
	{
		printf("Nbr: %d\n", tmp->nbr);
		printf("Index: %d\n", tmp->index);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

    if (argc > 2)
    {
	    stack_a = ft_init_stack();
	    stack_b = ft_init_stack();
	    if (!stack_a || !stack_b)
            ft_error_handler(stack_a, stack_b);
		ft_parse_manager(argc, argv, stack_a);
		ft_assign_index(stack_a);
		ft_print_stack(stack_a);
    }
}