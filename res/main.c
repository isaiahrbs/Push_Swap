/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:35:48 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/28 09:17:55 by irobinso         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.size_a = 0;
	stacks.size_b = 0;
	if (argc < 2 || (!check_args(argc, argv, &stacks)))
	{
		ft_printf("Error\n");
		return (0);
	}
	sorting(&stacks);
	free_stacks(&stacks);
	return (0);
}
