/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:18:53 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/15 15:16:28 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# define MY_INT_MIN -2147483648
# define MY_INT_MAX 2147483647

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		value;
}	t_stack;

// parse input
int	ft_valid_number_format(char *str);
int	ft_atoi_checker(char *str);
void	ft_parse_manager(int argc, char **argv, t_stack *stack_a);


// init
t_stack *ft_init_stack();

#endif
