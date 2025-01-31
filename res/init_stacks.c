/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:36:32 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/31 11:15:13 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	count_numbers(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && isspace(str[i]))
			i++;
		if (str[i] && !isspace(str[i]))
		{
			count++;
			while (str[i] && !isspace(str[i]))
				i++;
		}
	}
	return (count);
}

char	*merge_str(int argc, char **argv)
{
	char	*str;

	if (argc > 2)
		str = concat_args(argc, argv);
	else
		str = argv[1];
	return (str);
}

int	init_stacks(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	int		num_count;
	char	*str;
	char	**numbers;

	str = merge_str(argc, argv);
	numbers = ft_split(str, ' ');
	num_count = count_numbers(str);
	if (argc > 2)
		free(str);
	stacks->stack_a = malloc(sizeof(int) * num_count);
	stacks->stack_b = malloc(sizeof(int) * num_count);
	if (!stacks->stack_a || !stacks->stack_b)
	{
		free_stacks(stacks);
		return (0);
	}
	i = -1;
	while (++i < num_count)
		stacks->stack_a[i] = ft_atol(numbers[i]);
	free_shelf(numbers);
	stacks->size_a = num_count;
	stacks->size_b = 0;
	stacks->max_size = num_count;
	return (1);
}
