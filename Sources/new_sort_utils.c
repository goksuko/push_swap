/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_sort_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 00:16:54 by akaya-oz      #+#    #+#                 */
/*   Updated: 2025/03/29 22:43:48 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// if the numbers are both at the first half (above) of their list
void	rotate_and_finish(t_stack **a, t_stack **b, t_stack *best_b)
{
	int		i;

	i = 0;
	// we are going to rotate both stacks with one function
	while (i < best_b->index && i < best_b->index_a)
	{
		ps_rotate_both(a, b);
		i++;
	}
	// when we found at least one of the best numbers
	// then we are going to rotate the other stack to find the other best number
	while (i < best_b->index_a)
	{
		ps_rotate(a, "a");
		i++;
	}
	while (i < best_b->index)
	{
		ps_rotate(b, "b");
		i++;
	}
}

// if the numbers are both at the second half (below) of their list
void	reverse_rotate_and_finish(t_stack **a, t_stack **b, t_stack *best_b)
{
	int		length_a;
	int		length_b;
	int		i;

	i = 0;
	length_a = ps_find_length(a);
	length_b = ps_find_length(b);
	// we are going to reverse rotate both stacks with one function
	while (i < (length_b - best_b->index) && i < (length_a - best_b->index_a))
	{
		ps_reverse_rotate_both(a, b);
		i++;
	}
	// when we found at least one of the best numbers
	// then we are going to reverse rotate the other stack to find the other best number
	while (i < (length_a - best_b->index_a))
	{
		ps_reverse_rotate(a, "a");
		i++;
	}
	while (i < (length_b - best_b->index))
	{
		ps_reverse_rotate(b, "b");
		i++;
	}
}

// if the number in stack a is in the first half and the number in stack b is in the second half
void	a_first_b_second(t_stack **a, t_stack **b, t_stack *best_b)
{
	int		length_b;
	int		i;

	i = 0;
	length_b = ps_find_length(b);
	while (i < best_b->index_a)
	{
		ps_rotate(a, "a");
		i++;
	}
	i = 0;
	while (i < (length_b - best_b->index))
	{
		ps_reverse_rotate(b, "b");
		i++;
	}
}

// if the number in stack b is in the first half and the number in stack a is in the second half
void	a_second_b_first(t_stack **a, t_stack **b, t_stack *best_b)
{
	int		length_a;
	int		max_a;
	int		i;

	i = 0;
	length_a = ps_find_length(a);
	max_a = find_max(a);
	while (i < (length_a - best_b->index_a))
	{
		ps_reverse_rotate(a, "a");
		i++;
	}
	i = 0;
	while (i < best_b->index)
	{
		ps_rotate(b, "b");
		i++;
	}
	if ((*a)->value < (*b)->value && (*b)->value < max_a)
		ps_rotate(a, "a");
}
