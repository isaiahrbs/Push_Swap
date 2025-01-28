/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:35:25 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/28 12:54:14 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// if there is only 2 numbers and the one before is bigger, swap.
int	sort_two(t_stacks *stacks)
{
	if (stacks->size_a != 2)
		return (0);
	if (stacks->stack_a[0] > stacks->stack_a[1])
	{
		sa(stacks);
		printf("sa");
	}
	return (1);
}

//sort 3 numbers
int	sort_three(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stack_a[0];
	b = stacks->stack_a[1];
	c = stacks->stack_a[2];
	if (a > b && b < c && a < c)
		sa(stacks);
	else if (a > b && b > c)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (a > b && b < c && a > c)
		ra(stacks);
	else if (a < b && b > c && a < c)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (a < b && b > c && a > c)
		rra(stacks);
	return (1);
}

//sort 4 numbers
void	sort_four(t_stacks *stacks)
{
	int	min;
	int	i;

	i = 0;
	min = find_min(stacks->stack_a, stacks->size_a);
	while (stacks->stack_a[0] != min)
	{
		if (i > stacks->size_a / 2)
			rra(stacks);
		else
			ra(stacks);
		i++;
	}
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}

//sort 5 numbers
void	sort_five(t_stacks *stacks)
{
	int	min;
	int	i;

	i = 0;
	min = find_min(stacks->stack_a, stacks->size_a);
	while (stacks->stack_a[0] != min)
	{
		if (i > stacks->size_a / 2)
			rra(stacks);
		else
			ra(stacks);
		i++;
	}
	pb(stacks);
	sort_four(stacks);
	pa(stacks);
}
