/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:37:08 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/29 00:16:13 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <ctype.h>
# include "../libraries/libft/inc/libft.h"

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;// size of the stack
	int	size_b;// size of the stack
	int	max_size;// maximum size of the stack
}	t_stacks;

//---functions---//

int		check_args(int argc, char **argv, t_stacks *stacks);

long	ft_safe_atol(const char *str);

void	free_stacks(t_stacks *stacks);

void	free_shelf(char **numbers);

void	print_stacks(t_stacks *stacks);

void	radix_sort(t_stacks *stacks);

int		sorting(t_stacks *stacks);

int		check_numbers_int(char **numbers, int count);

int		contains_space(char **strs, int count);

int		is_valid_number(char *str);

int		count_numbers(char *str);

int		check_duplicates(int *arr, int size);

int		find_min(int *stack, int size);

int		find_max(int *stack, int size);

int		calculate_length(int argc, char **argv);

char	*concat_args(int argc, char **argv);

int		is_sorted(t_stacks *stacks);

//---stack manipulation operations---//

//--reverse rotate--//
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

//--rotate--//
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

//--swap--/
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

//--push--//
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

//---sorting operations---//

int		sort_two(t_stacks *stacks);
int		sort_three(t_stacks *stacks);
void	sort_four(t_stacks *stacks);
void	sort_five(t_stacks *stacks);

#endif
