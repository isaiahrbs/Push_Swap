/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:58:01 by irobinso          #+#    #+#             */
/*   Updated: 2025/02/11 19:00:24 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_empty(char **numbers)
{
	if (!numbers || !numbers[0])
		return (1);
	if (ft_strlen(numbers[0]) == 0)
		return (1);
	if (is_only_spaces(numbers[0]))
		return (1);
	return (0);
}

int	check_numbers_int(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
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

int	is_sorted(char **number_list)
{
	int		i;
	long	prev;
	long	current;

	i = 1;
	prev = ft_atol(number_list[0]);
	while (number_list[i])
	{
		current = ft_atol(number_list[i]);
		if (current < prev)
			return (0);
		prev = current;
		i++;
	}
	return (1);
}

int	is_number(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(char **number_list)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 0;
	while (number_list[i])
	{
		num_i = atol(number_list[i]);
		j = i + 1;
		while (number_list[j])
		{
			num_j = atol(number_list[j]);
			if (num_i == num_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
