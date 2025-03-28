/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oper_rotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/08 11:57:13 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

//rotate: Shift up all elements of stack by 1.
//The first element becomes the last one.
void	ps_rotate(t_stack **stack, char *str)
{
	t_stack	*current;
	t_stack	*temp;

	current = *stack;
	if (current == NULL || current->next == NULL)
		return ;
	else
	{
		temp = current;
		*stack = current->next;
		temp->next = NULL;
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = temp;
	}
	if (*str == 'a')
		write(1, "ra\n", 3);
	else if (*str == 'b')
		write(1, "rb\n", 3);
}

void	ps_rotate_both(t_stack **a, t_stack **b)
{
	ps_rotate(a, "");
	ps_rotate(b, "");
	write(1, "rr\n", 3);
}
