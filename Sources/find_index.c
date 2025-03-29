/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_index.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 23:48:19 by akaya-oz      #+#    #+#                 */
/*   Updated: 2025/03/29 22:27:28 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// writes the index of the number in the stack
void	give_position_index(t_stack **stack)
{
	t_stack	*current;
	int		index_no;

	index_no = 0;
	current = *stack;
	while (current)
	{
		current->index = index_no;
		index_no++;
		current = current->next;
	}
}

// writes the distance of the number from the top or bottom of the stack
void	give_price(t_stack **stack)
{
	t_stack	*current;
	int		length;

	current = *stack;
	length = ps_find_length(stack);
	current = *stack;
	while (current)
	{
		if (2 * current->index < length)
		{
			current->price = current->index;
			current->second_half = false;
		}
		else
		{
			current->price = length - current->index;
			current->second_half = true;
		}
		current = current->next;
	}
}

int	find_index_a_helper(t_stack **a, t_stack *current_b, int max_a, int min_a)
{
	int			temp;
	t_stack		*current_a;
	int			length_a;

	current_a = *a;
	length_a = ps_find_length(a);
	// if current_b is bigger or smaller than all the numbers in a
	// we need to put it right after the max value of a
	if (current_b->value > max_a || current_b->value < min_a) 
	{
		while (current_a->value != max_a && current_a->next)
			current_a = current_a->next;
		temp = current_a->index + 1;
	}
	else
	{
		// if current_b is in the middle of a, we need to find the right place
		// so we need to iterate till the situation is changed
		while (current_b->value < current_a->value && current_a->next)
			current_a = current_a->next;
		while (current_b->value > current_a->value && current_a->next)
			current_a = current_a->next;
		temp = current_a->index;
		// after iteration if we come the beginning of the stack
		// that means there is no need to iterate stack a
		if (current_b->value > current_a->value)
			temp = 0;
	}
	// after iteration if we come the end of the stack
	// that means there is no need to iterate stack a
	if (temp == length_a)
		temp = 0;
	return (temp);
}

// finds the index of the number in stack a corresponding to the number in stack b
void	find_index_a(t_stack **a, t_stack **b)
{
	t_stack		*current_b;
	int			max_a;
	int			min_a;

	max_a = find_max(a);
	min_a = find_min(a);
	current_b = *b;
	while (current_b)
	{
		current_b->index_a = find_index_a_helper(a, current_b, max_a, min_a);
		current_b = current_b->next;
	}
}
