/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 13:53:50 by akaya-oz      #+#    #+#                 */
/*   Updated: 2025/03/29 22:44:23 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

t_stack	*find_best_a(t_stack **a, t_stack *best_b)
{
	t_stack	*current_a;
	int		times;

	current_a = *a;
	times = best_b->index_a;
	while (times--)
		current_a = current_a->next;
	return (current_a);
}

void	do_cash_job(t_stack **a, t_stack **b, t_stack *best_a, t_stack *best_b)
{
	bool		second_half_a;
	bool		second_half_b;

	second_half_a = best_a->second_half;
	second_half_b = best_b->second_half;
	// if the numbers are both at the first half (above) of their list
	if (!second_half_a && !second_half_b)
		rotate_and_finish(a, b, best_b);
	else if (!second_half_a && second_half_b)
		a_first_b_second(a, b, best_b);
	else if (second_half_a && !second_half_b)
		a_second_b_first(a, b, best_b);
	else if (second_half_a && second_half_b)
		reverse_rotate_and_finish(a, b, best_b);
	// we have finished the moves for the best numbers
	// now we need to push the best number in stack b to stack a
	ps_push(b, a, "a");
}

// calculates the total moves needed for each of the numbers in stack b
void	find_total_price(t_stack **a, t_stack **b)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			times;

	current_b = *b;
	// we know the price of every number in stack a and stack b
	// however, we need to find the total moves needed for each element in stack b
	while (current_b)
	{
		current_a = *a;
		// we know the index of the corresponding number in stack a
		times = current_b->index_a;
		while (times--)
			current_a = current_a->next;
		// after iterating, we are at the corresponding number in stack a
		// we can add the price of the number in stack a to the price of the number in stack b
		current_b->price += current_a->price;
		current_b = current_b->next;
	}
}

// finds the best number in stack b to put to stack a
void	find_best_and_cash(t_stack **a, t_stack **b)
{
	t_stack		*current_b;
	t_stack		*best_a;
	t_stack		*best_b;
	int			min_price;

	min_price = INT_MAX;
	current_b = *b;
	best_b = NULL;
	while (current_b)
	{
		if (current_b->price < min_price)
		{
			min_price = current_b->price;
			best_b = current_b;
		}
		current_b = current_b->next;
	}
	// we found the cheapest number in stack b
	// now we need to find the corresponding number in stack a
	best_a = find_best_a(a, best_b);
	// it is time to make moves according to our calculations
	do_cash_job(a, b, best_a, best_b);
}

void	do_new_sort(t_stack **a, int length)
{
	t_stack		*b;
	int			times;

	b = NULL;
	times = length - 3;
	while (times--)
		ps_push(a, &b, "b");
	if (!ps_check_if_sorted(a))
		do_for_three(a);
	while (b)
	{
		give_position_index(a); // write the index of the number in the stack
		give_price(a); // write the distance of the number from the top or bottom of the stack
		give_position_index(&b);
		give_price(&b);
		find_index_a(a, &b); // find the index of the next number in stack a to put to the place accordingly
		find_total_price(a, &b); // calculate the total moves needed for each of the numbers in stack b
		find_best_and_cash(a, &b); // find the best number in stack b to put to stack a
	}
	sort_eff_a(a); // when all the numbers are in stack a, take the min to the top
}
