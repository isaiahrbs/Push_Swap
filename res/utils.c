/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:30:16 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/30 21:41:02 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*concat_args(int argc, char **argv)
{
	char	*result;
	int		total_length;
	int		i;
	int		pos;

	i = 1;
	pos = 0;
	total_length = calculate_length(argc, argv);
	result = malloc(sizeof(char) * (total_length + 1));
	if (!result)
		return (NULL);
	while (i < argc)
	{
		pos += ft_strlcpy(result + pos, argv[i], total_length - pos + 1);
		if (i < argc - 1)
		{
			result[pos] = ' ';
			pos++;
		}
		i++;
	}
	result[total_length] = '\0';
	return (result);
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

void	free_stacks(t_stacks *stacks)
{
	if (stacks->stack_a)
		free(stacks->stack_a);
	if (stacks->stack_b)
		free(stacks->stack_b);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
}
