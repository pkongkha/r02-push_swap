/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split_get_next_memb.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:31:58 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:59:45 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"
#include "stack_loc.h"

int	chunk_split_get_next_memb(struct s_circ_stack *a, struct s_circ_stack *b,
	struct s_stack_loc *loc)
{
	if (loc->id == A)
	{
		if (loc->pos == TOP)
			return (*a->top);
		else
			return (*a->bottom);
	}
	else
	{
		if (loc->pos == TOP)
			return (*b->top);
		else
			return (*b->bottom);
	}
	return (-1);
}
