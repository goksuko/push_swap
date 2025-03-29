/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/10 23:47:15 by akaya-oz      #+#    #+#                 */
/*   Updated: 2025/03/29 18:02:28 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/checker.h"

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

char	*do_operation2(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		ps_reverse_rotate(a, "");
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'
		&& line[3] == '\n')
		ps_reverse_rotate(b, "");
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r'
		&& line[3] == '\n')
	{
		ps_reverse_rotate(a, "");
		ps_reverse_rotate(b, "");
	}
	return (get_next_line(0));
}

char	*do_operation(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ps_swap(a, "");
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ps_swap(b, "");
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ps_push(b, a, "");
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ps_push(a, b, "");
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ps_rotate(a, "");
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ps_rotate(b, "");
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
	{
		ps_rotate(a, "");
		ps_rotate(b, "");
	}
	else
		return (do_operation2(a, b, line));
	return (get_next_line(0));
}

void	do_check(t_stack **a, t_stack **b, char *line)
{
	char	*temp;

	while (line && *line != '\n')
	{
		temp = line;
		line = do_operation(a, b, line);
		free(temp);
	}
	if (*b)
		write(2, "\033[0;31mKO\033[0m\n", 15);
	else if (!ps_check_if_sorted(a))
		write(2, "\033[0;31mKO\033[0m\n", 15);
	else
		write(1, "\033[0;32mOK\033[0m\n", 15);
	free(line);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	char	**args;

	if (ps_initial_probs(argc, argv))
		return (1);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
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
	if (!a)
	 	return (ps_write_error(ERROR_UNDEFINED));
	b = NULL;
	line = get_next_line(0);
	if (!line && !ps_check_if_sorted(&a))
		write(2, "\033[0;31mKO\033[0m\n", 15);
	else if (!line && ps_check_if_sorted(&a))
		write(1, "\033[0;32mOK\033[0m\n", 15);
	else
		do_check(&a, &b, line);
	if (a != NULL)
		a = ps_free_list(a);
	if (b != NULL)
		b = ps_free_list(b);
	return (0);
}
