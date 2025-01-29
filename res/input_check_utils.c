/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:23:48 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/28 15:44:27 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	contains_space(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (ft_strchr(strs[i], ' '))
			return (1);
		i++;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	long	number;

	number = ft_atol(str);
	if (number > INT_MAX || number < INT_MIN)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	count_numbers(char *str)
{
	int	count;
	int	in_number;

	count = 0;
	in_number = 0;
	while (*str)
	{
		if (*str != ' ' && !in_number)
		{
			count++;
			in_number = 1;
		}
		else if (*str == ' ')
			in_number = 0;
		str++;
	}
	return (count);
}

int	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
