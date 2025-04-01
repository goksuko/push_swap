/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:54 by akaya-oz      #+#    #+#                 */
/*   Updated: 2025/03/31 22:14:02 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ps_take_numbers(t_stack **a, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		*a = ps_arguments_to_stack_a(args[i], a);
		i++;
	}
	return ;
}

bool	ps_check_probs(char **args)
{
	if (ps_check_non_num(args))
		return (ps_write_error(ERROR_NON_NUM));
	if (ps_big_num(args))
		return (ps_write_error(ERROR_BIG_NUM));
	if (ps_check_dupp(args))
		return (ps_write_error(ERROR_DUPLICATE));
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	char	**args;

	if (ps_initial_probs(argc, argv))
		return (ps_write_error(ERROR_ARGUMENT_COUNT));
	if (ft_strncmp(argv[1], "radix", 6) == 0)
		return(ps_radix(argc, argv));
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (args == NULL)
			return (ps_write_error(ERROR_ALLOCATION));
	}
	else
		args = argv + 1;
	if (ps_check_probs(args))
	{
		if (argc == 2)
			free_matrix(args);
		return (1);
	}
	a = NULL;
	ps_take_numbers(&a, args);
	if (a == NULL)
	{
		if (argc == 2)
			free_matrix(args);
		return (ps_write_error(ERROR_ALLOCATION));
	}
	if (ps_check_if_sorted(&a))
		ps_write_error(SORTED);
	else
		ps_sort(&a);
	if (a)
		a = ps_free_list(a);
	if (argc == 2)
		free_matrix(args);
	return (0);
}
