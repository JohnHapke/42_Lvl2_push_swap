/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:33:18 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/24 11:57:36 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_manager(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	**arg;

	i = 0;
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		if (!arg)
			ft_error_handler(stack, NULL);
		ft_parse_control(arg, stack);
		while (arg[i])
			free (arg[i++]);
		free (arg);
	}
	else
		ft_parse_control(argv + 1, stack);
	ft_assign_index(stack);
}

void	ft_parse_control(char **arg, t_stack *stack)
{
	int	i;
	int	num;

	i = -1;
	while (arg[++i] != NULL)
	{
		if (ft_valid_number_format(arg[i]) == -1)
			ft_error_handler(stack, NULL);
		num = ft_atoi_checker(arg[i]);
		if (num == 0 && arg[i][0] != '0')
			ft_error_handler(stack, NULL);
		if (ft_duplicate_checker(stack, num) == -1)
			ft_error_handler(stack, NULL);
		ft_add_to_stack(stack, num);
	}
}

int	ft_duplicate_checker(t_stack *stack, int num)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp != NULL)
	{
		if (tmp->nbr == num)
			return (-1);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_atoi_checker(char *str)
{
	int		i;
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if (!str[i])
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	nbr *= sign;
	if (nbr < MY_INT_MIN || nbr > MY_INT_MAX)
		return (0);
	return (nbr);
}

int	ft_valid_number_format(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (-1);
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '\0')
			return (-1);
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}
