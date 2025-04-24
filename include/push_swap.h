/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:18:53 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/24 12:21:25 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define MY_INT_MIN -2147483648
# define MY_INT_MAX 2147483647

typedef enum e_ops
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}	t_ops;

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_best_move
{
	int	best_pos_b;
	int	best_pos_a;
	int	element_value;
	int	min_cost;
	int	min_index;
	int	pos_a;
	int	min_pos_a;
}	t_best_move;

// parse input
int		ft_valid_number_format(char *str);
int		ft_atoi_checker(char *str);
void	ft_parse_manager(int argc, char **argv, t_stack *stack_a);
int		ft_duplicate_checker(t_stack *stack, int num);
void	ft_parse_control(char **arg, t_stack *stack);

// init
t_stack	*ft_init_stack(void);
void	ft_add_to_stack(t_stack *stack, int num);
t_node	*ft_create_node(int num);
void	ft_assign_index(t_stack *stack);

// memory & error
void	ft_free_stack(t_stack *stack);
void	ft_error_handler(t_stack *stack_a, t_stack *stack_b);
int		ft_is_sorted(t_stack *stack);

// small algorithm
void	ft_sort_two(t_stack *stack);
void	ft_sort_three(t_stack *stack);
void	ft_sort_five(t_stack *a, t_stack *b);

//operations handler
void	ft_push_handler(t_stack *stack_a, t_stack *stack_b, t_ops flag);
void	ft_swap_handler(t_stack *a, t_stack *b, t_ops flag);
void	ft_rotate_handler(t_stack *a, t_stack *b, t_ops flag);
void	ft_reverse_rotate_handler(t_stack *a, t_stack *b, t_ops flag);

// operations ft
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

// principal algorithm
void	ft_sort_handler(t_stack *a, t_stack *b);
void	ft_partition_stack(t_stack *a, t_stack *b);
void	ft_cost_calculation(t_stack *a, t_stack *b, t_best_move *best_move);
int		ft_total_cost(t_stack *a, t_stack *b, int pos_b, int pos_a);
int		ft_cost_operation(t_stack *stack, int pos);
int		ft_position_a(t_stack *a, int index_b, t_best_move *best_move);
int		ft_pos_m_index(t_stack *a, int m_index, int code);
int		ft_pos_index(t_stack *a, int index_b);
void	ft_exec_best_move(t_stack *a, t_stack *b, t_best_move *best_move);
void	ft_rot_exec(t_stack *a, int rot_count, int rotate_up, int code);
int		ft_rot_count(int size, int pos);
int		ft_rot_up(int size, int pos);

#endif
