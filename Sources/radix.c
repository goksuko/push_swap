/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/30 18:11:10 by akaya-oz      #+#    #+#                 */
/*   Updated: 2025/04/01 16:31:16 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

t_radix *radix_arguments_to_stack_a(char *string, t_radix **a)
{
	int		nb;
	t_radix	*new_t_radix;
	t_radix	*current;

	nb = (int)ps_string_to_long(string);
	new_t_radix = malloc(1 * sizeof(t_radix));
	if (new_t_radix == NULL)
		return (radix_free_list(*a), NULL);
	new_t_radix->value = nb;
	new_t_radix->next = NULL;
	current = *a;
	if (current == NULL)
		*a = new_t_radix;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_t_radix;
	}
	return (*a);
}

void radix_take_numbers(t_radix **a, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		*a = radix_arguments_to_stack_a(args[i], a);
		i++;
	}
	return ;
}

int ps_radix_sort(char **args, int argc)
{
	t_radix	*a;

	a = NULL;
	radix_take_numbers(&a, args);
	if (a == NULL)
	{
		if (argc == 3)
			free_matrix(args);
		return (ps_write_error(ERROR_ALLOCATION));
	}
	if (radix_check_if_sorted(&a))
		ps_write_error(SORTED);
	else
		radix_sort(&a);
	if (a)
		a = radix_free_list(a);
	return (0);	
} 

int	ps_radix(int argc, char **argv)
{
	char **args;

	if (argc == 3)
	{
		args = ft_split(argv[2], ' ');
		if (args == NULL)
			return (ps_write_error(ERROR_ALLOCATION));
	}
	else
		args = argv + 2;
	if (ps_check_probs(args))
	{
		if (argc == 2)
			free_matrix(args);
		return (1);
	}
	if (ps_radix_sort(args, argc))
		return (1);
	if (argc == 3)
		free_matrix(args);
	return (0);
}