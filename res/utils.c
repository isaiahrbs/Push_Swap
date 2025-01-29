/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:30:16 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/28 20:47:36 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_a - 1)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

long	ft_safe_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*void	print_stacks(t_stacks *stacks)
{
	int	i;
	int	max_size;

	if (stacks->size_a > stacks->size_b)
		max_size = stacks->size_a;
	else
		max_size = stacks->size_b;
	printf("\n");
	printf("Stack A  Stack B\n");
	printf("-------------------\n");
	i = 0;
	while (i < max_size)
	{
		if (i < stacks->size_a)
			printf("%-7d ", stacks->stack_a[i]);
		else
			printf("		");
		if (i < stacks->size_b)
			printf("%d", stacks->stack_b[i]);
		printf("\n");
		i++;
	}
	printf("-------------------\n\n\n");
}*/

int	calculate_length(int argc, char **argv)
{
	int	total_length;
	int	i;

	total_length = 0;
	i = 1;
	while (i < argc)
	{
		total_length = total_length + ft_strlen(argv[i]);
		if (i < argc - 1)
			total_length++;
		i++;
	}
	return (total_length);
}

//find the minimum number in the stack
int	find_min(int *stack, int size)
{
	int	min;
	int	i;

	i = 0;
	min = stack[i];
	while (i < size)
	{
		if (stack[i] < min)
			min = stack[i];
		i++;
	}
	return (min);
}

int	find_max(int *stack, int size)
{
	int	max;
	int	i;

	i = 0;
	max = stack[i];
	while (i < size)
	{
		if (stack[i] > max)
			max = stack[i];
		i++;
	}
	return (max);
}
