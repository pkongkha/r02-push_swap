/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:01:52 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/14 17:00:19 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "op.h"
#include "sort.h"
#include "stack_loc.h"

#include <errno.h>

int sort_three(struct s_op_info *info, struct s_chunk *c)
{
	int (*func_sort)(struct s_op_info *info);

	if (c->size != 3)
		return (-EINVAL);
	if (c->loc.id == A)
	{
		if (c->loc.pos == TOP)
			func_sort = &sort_three_flow_a_top;
		else if (c->loc.pos == BOTTOM)
			func_sort = &sort_three_flow_a_bottom;
		else
			return (-EINVAL);
	}
	else if (c->loc.id == B)
	{
		if (c->loc.pos == TOP)
			func_sort = &sort_three_flow_b_top;
		else if (c->loc.pos == BOTTOM)
			func_sort = &sort_three_flow_b_bottom;
		else
			return (-EINVAL);
	}
	else
		return (-EINVAL);
	return (func_sort(info));
}
