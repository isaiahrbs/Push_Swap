/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:35:48 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/29 10:40:14 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	if (stacks->stack_a)
		free(stacks->stack_a);
	if (stacks->stack_b)
		free(stacks->stack_b);
}

void	error_exit(t_stacks *stacks)
{
	if (stacks)
		free_stacks(stacks);
	write(2, "Error\n", 6);
	exit(1);
}

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9')
				|| ((argv[i][j] == '-') || (argv[i][j] == '+')
				|| (argv[i][j] == ' '))))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.size_a = 0;
	stacks.size_b = 0;
	if (argc < 2)
		return (0);
	if (!check_digits(argc, argv))
	{
		ft_printf("Error\n");
		free_stacks(&stacks);
		return (0);
	}
	if (!check_args(argc, argv, &stacks))
	{
		ft_printf("Error\n");
		free_stacks(&stacks);
		return (0);
	}
	if (is_sorted(&stacks))
		return (0);
	sorting(&stacks);
	free_stacks(&stacks);
	return (0);
}
