/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_flow_detect_scheme_bottom.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 01:47:39 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:44:55 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

int	sort_three_flow_detect_scheme_bottom(struct s_circ_stack *cs)
{
	const int	a = circ_stack_seek_bottom(cs, 2);
	const int	b = circ_stack_seek_bottom(cs, 1);
	const int	c = circ_stack_seek_bottom(cs, 0);

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
