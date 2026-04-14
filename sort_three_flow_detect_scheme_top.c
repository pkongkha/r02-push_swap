/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_flow_detect_scheme_top.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 01:47:39 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/15 02:14:51 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

int sort_three_flow_detect_scheme_top(struct s_circ_stack *cs)
{
	const int	a = circ_stack_seek(cs, 0);
	const int	b = circ_stack_seek(cs, 1);
	const int	c = circ_stack_seek(cs, 2);

	if (a < b && a < c)
	{
		if (b < c)
			return (123);
		else
			return (132);
	}
	else if (a > b && a > c)
	{
		if (b < c)
			return (312);
		else
			return (321);
	}
	else
	{
		if (b < c)
			return (213);
		else
			return (231);
	}
}
