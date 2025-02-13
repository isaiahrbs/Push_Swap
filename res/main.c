/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:53:42 by irobinso          #+#    #+#             */
/*   Updated: 2025/02/11 18:31:50 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.size_a = 0;
	stacks.size_b = 0;

	if (!proceed_checks(argc, argv))
		return (0);
	if (!init_stacks(argc, argv, &stacks))
		return (0);
	sorting(&stacks);
	free_stacks(&stacks);
	return (0);
}
