/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_add_strsnums.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:08:18 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/19 00:58:29 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

#include <libft.h>

static size_t	circ_stack_add_strnums(t_circ_stack *cs, char *strnums)
{
	size_t	num_count;

	num_count = 0;
	while (1)
	{
		while (ft_isspace(*strnums))
			++strnums;
		if (!ft_isdigit(*strnums) && *strnums != '+' && *strnums != '-')
			break ;
		circ_stack_push_bottom(cs, ft_atoi(strnums));
		++num_count;
		if (*strnums == '+' || *strnums == '-')
			++strnums;
		while (ft_isdigit(*strnums))
			++strnums;
	}
	return (num_count);
}

size_t	circ_stack_add_strsnums(t_circ_stack *cs, char **strsnums, size_t nstr)
{
	size_t	num_count;

	num_count = 0;
	while (nstr)
	{
		num_count += circ_stack_add_strnums(cs, *strsnums++);
		--nstr;
	}
	return (num_count);
}
