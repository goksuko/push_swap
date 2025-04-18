/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/10 23:47:15 by akaya-oz      #+#    #+#                 */
/*   Updated: 2025/03/29 17:54:36 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/checker.h"

bool	ps_check_probs(char **args)
{
	if (ps_check_non_num(args))
		return (1);
	if (ps_big_num(args))
		return (1);
	if (ps_check_dupp(args))
		return (1);
	return (0);
}