/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/31 22:33:14 by akaya-oz      #+#    #+#                 */
/*   Updated: 2025/04/01 23:19:19 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

t_radix	*radix_free_list(t_radix *t_radix)
{
	if (t_radix != NULL)
	{
		radix_free_list(t_radix->next);
		free(t_radix);
		t_radix = NULL;
	}
	return (NULL);
}

bool radix_check_if_sorted(t_radix **a)
{
	t_radix	*current;
	t_radix	*temp;

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

void write_indexes(t_radix **a)
{
	t_radix	*current;
	t_radix	*temp;
	int		i;

	current = *a;
	while (current != NULL)
	{
		temp = *a;
		i = 0;
		while (temp != NULL)
		{
			if (current->value > temp->value)
				i++;
			temp = temp->next;
		}
		current->index = i;
		current = current->next;
	}
}

int radix_find_length(t_radix **a)
{
	int		i;
	t_radix	*current;

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

void radix_push(t_radix **src, t_radix **dest, char *str)
{
	t_radix	*temp;

	if (*src == NULL)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
	ps_push_writer(str);
}

void radix_rotate(t_radix **a)
{
	t_radix	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	t_radix	*current = *a;
	while (current->next != NULL)
		current = current->next;
	current->next = temp;
	write(1, "ra\n", 3);
}


void do_radix_sort(t_radix **a, t_radix **b, int length)
{
	int		i;
	int		j;
	int		max_index;

	i = 0;
	max_index = 0;
	while (((length - 1) >> max_index) != 0)
		++max_index;
	while (i < max_index)
	{
		j = 0;
		while (j < length && *a)
		{
			if (radix_check_if_sorted(a))
				break ;
			if ((((*a)->index >> i) & 1) == 0)
				radix_push(a, b, "b");
			else
				radix_rotate(a);
			j++;
		}
		while (*b)
			radix_push(b, a, "a");
		i++;
	}
}

void radix_sort(t_radix **a)
{
	int length;
	t_radix	*b;

	b = NULL;
	write_indexes(a);
	length = radix_find_length(a);
	do_radix_sort(a, &b, length);
}