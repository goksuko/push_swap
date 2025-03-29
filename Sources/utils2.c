/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 15:44:00 by akaya-oz      #+#    #+#                 */
/*   Updated: 2025/03/29 19:23:45 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	*free_matrix(char **array)
{
	int	i;

	i = 0;
	while (array && array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	if (array)
	{
		free(array);
		array = NULL;
	}
	return (NULL);
}

t_stack	*ps_free_list(t_stack *t_stack)
{
	if (t_stack != NULL)
	{
		ps_free_list(t_stack->next);
		free(t_stack);
	}
	return (NULL);
}

int	ps_find_length(t_stack **a)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = *a;
	if (current == NULL)
		return (0);
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	ps_write_error(char *str)
{
	write(2, "\033[0;31m", 8);
	write(2, str, ft_strlen(str));
	write(2, "\033[0m", 4);
	return (1);
}

void	ps_print_stack(t_stack *a)
{
	t_stack		*current;
	int			i;

	current = a;
	i = 0;
	if (current == NULL)
		ft_printf("Stack is empty.\n");
	else
	{
		while (current != NULL)
		{
			ft_printf("Stack %d: %d\n", i, current->value);
			i++;
			current = current->next;
		}
	}
}
