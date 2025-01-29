/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:46:31 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/29 10:40:34 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_numbers_int(char **numbers, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (ft_strlen(numbers[i]) > 11 || ft_atol(numbers[i]) > INT_MAX
			|| ft_atol(numbers[i]) < INT_MIN)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	free_shelf(char **numbers)
{
	int	i;

	i = -1;
	if (!numbers)
		return ;
	while (numbers[++i])
		free(numbers[i]);
	free(numbers);
}

static int	init_and_validate_stack(t_stacks *stacks, char **numbers, int count)
{
	int	i;

	stacks->stack_a = malloc(sizeof(int) * count);
	stacks->stack_b = malloc(sizeof(int) * count);
	if (!stacks->stack_a || !stacks->stack_b)
	{
		free_stacks(stacks);
		return (0);
	}
	i = -1;
	while (++i < count)
		stacks->stack_a[i] = ft_safe_atol(numbers[i]);
	if (!check_numbers_int(numbers, count))
	{
		free_shelf(numbers);
		return (0);
	}
	if (check_duplicates(stacks->stack_a, count))
	{
		free_shelf(numbers);
		return (0);
	}
	stacks->size_a = count;
	stacks->size_b = 0;
	return (1);
}

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

int	check_args(int argc, char **argv, t_stacks *stacks)
{
	char	**numbers;
	char	*str;
	int		num_count;

	if (argc > 2)
		str = concat_args(argc, argv);
	else
		str = argv[1];
	if (str)
	{
		numbers = ft_split(str, ' ');
		num_count = count_numbers(str);
	}
	if (!init_and_validate_stack(stacks, numbers, num_count))
	{
		if (argc > 2)
			free(str);
		return (0);
	}
	stacks->max_size = num_count;
	free_shelf(numbers);
	return (1);
}
