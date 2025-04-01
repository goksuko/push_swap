/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:48 by akaya-oz      #+#    #+#                 */
/*   Updated: 2025/03/31 22:17:05 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

t_stack	*ps_write_in_stack_a(t_stack **a, int nb)
{
	t_stack	*new_t_stack;
	t_stack	*current;

	new_t_stack = malloc(1 * sizeof(t_stack));
	if (new_t_stack == NULL)
		return (ps_free_list(*a), NULL);
	new_t_stack->value = nb;
	new_t_stack->next = NULL;
	current = *a;
	if (current == NULL)
		*a = new_t_stack;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_t_stack;
	}
	return (*a);
}

t_stack	*ps_arguments_to_stack_a(char *string, t_stack **a)
{
	int	nb;

	nb = (int)ps_string_to_long(string);
	*a = ps_write_in_stack_a(a, nb);
	return (*a);
}

bool	ps_check_if_sorted(t_stack **a)
{
	t_stack	*current;
	t_stack	*temp;

	current = *a;
	while (current->next != NULL)
	{
		temp = current->next;
		if (current->value > temp->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	clck_while_nb_edge(t_stack **stack, int edge)
{
	t_stack	*current;
	int		clock_wise;

	clock_wise = 0;
	current = *stack;
	while (current->value != edge && current)
	{
		clock_wise++;
		current = current->next;
	}
	return (clock_wise);
}
