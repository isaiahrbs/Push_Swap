/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:48:31 by irobinso          #+#    #+#             */
/*   Updated: 2025/02/11 18:46:34 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_value(char **number_list)
{
	if (is_empty(number_list))
		return (2);
	if (!is_number(number_list))
		return (1);
	if (!check_numbers_int(number_list))
		return (1);
	if (check_duplicates(number_list))
		return (1);
	if (is_sorted(number_list))
		return (2);
	return (0);
}

int	proceed_checks(int argc, char **argv)
{
	int		input_value;
	char	**number_list;
	char	*concatenated_args;

	if (argc == 2)
		number_list = ft_split(argv[1], ' ');
	else
	{
		concatenated_args = concat_args(argc, argv);
		number_list = ft_split(concatenated_args, ' ');
		free(concatenated_args);
	}
	input_value = get_value(number_list);
	free_shelf(number_list);
	if (input_value == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (input_value == 2)
		return (0);
	return (1);
}
