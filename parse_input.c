/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhapke <jhapke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:33:18 by jhapke            #+#    #+#             */
/*   Updated: 2025/04/15 15:02:07 by jhapke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_parse_manager(int argc, char **argv, t_stack *stack_a)
{
	int	i;
	int	num;
	
	i = 0;
	while (++i < argc)
	{
		if (ft_valid_number_format == -1)
			exit(1);
		num = ft_atoi_checker(argv[i]);
		if (!num)
			exit(1);
		if (num exists in stack_a)
		
	}
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
		exit(1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if (!str[i])
			exit(1);
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	nbr *= sign;
	if (nbr < MY_INT_MIN || nbr > MY_INT_MAX)
		exit(1);
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
			exit(1);
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

void	ft_input_checker(int argc, char **argv)
{
	int	i;
	int	*numbers;
	int	num;
	int	j;

	numbers = ft_calloc(argc - 1, sizeof(int));
	if (!numbers)
		exit(1);
	i = 0;
	while (++i < argc)
	{
		if (ft_valid_number_format(argv[i]) == -1)
			exit(1);
		num = ft_atoi_checker(argv[i]);
		j = -1;
		while (++j < i - 1)
		{
			if ( num == numbers[j])
			{
				exit(1);
				free(numbers);
			}
		}
		numbers[i - 1] = num;
	}
	free(numbers);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (argc > 2)
		ft_parse_manager(argc, argv, stack_a);
}
