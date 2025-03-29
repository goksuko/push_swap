/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:28:55 by akaya-oz      #+#    #+#                 */
/*   Updated: 2025/03/29 19:24:00 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_ARGUMENT_COUNT	"Please provide numbers to sort.\n"
# define ERROR_NON_NUM			"Please provide only numbers.\n"
# define ERROR_DUPLICATE		"Please provide only unique numbers.\n"
# define ERROR_BIG_NUM			"Please provide numbers between -2147483648 and 2147483647.\n"
# define ERROR_UNDEFINED		"Undefined error.\n"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*ps_arguments_to_stack_a(char *string, t_stack **a);
t_stack				*ps_free_list(t_stack *t_stack);
int					ps_write_error(char *str);
int					ps_check_if_sorted(t_stack **a);
void				ps_take_numbers(t_stack **a, char **args);
char				*get_next_line(int fd);
void				ps_push(t_stack **src, t_stack **dest, char *str);
void				ps_rotate(t_stack **stack, char *str);
void				ps_reverse_rotate(t_stack **stack, char *str);
void				ps_swap(t_stack **stack, char *str);
bool				ps_initial_probs(int argc, char *argv[]);
char				**ft_split(char const *s, char c);
void				*free_matrix(char **array);
bool				ps_check_probs(char **str);
bool				ps_check_in_array(long *array, long temp);
bool				ps_check_dupp(char **str);
bool				ps_check_non_num(char **str);
bool				ps_big_num(char **str);

#endif