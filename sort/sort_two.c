/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:54:00 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:44:27 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"
#include "op.h"
#include "sort.h"

#include <errno.h>

static int	sort_two_flow_a(struct s_op_info *info, struct s_chunk *c)
{
	if (c->loc.pos == TOP)
	{
		if (circ_stack_seek(&info->a, 0) > circ_stack_seek(&info->a, 1))
			return (op(info, SA));
		else
			return (0);
	}
	else if (c->loc.pos == BOTTOM)
	{
		if (circ_stack_seek_bottom(&info->a, 0)
			> circ_stack_seek_bottom(&info->a, 1))
			return (op_many(info, 2, (enum e_op[]){RRA, RRA}));
		else
			return (op_many(info, 3, (enum e_op[]){RRA, RRA, SA}));
	}
	else
		return (-EINVAL);
}

static int	sort_two_flow_b(struct s_op_info *info, struct s_chunk *c)
{
	if (c->loc.pos == TOP)
	{
		if (circ_stack_seek(&info->b, 0) > circ_stack_seek(&info->b, 1))
			return (op_many(info, 2, (enum e_op[]){PA, PA}));
		else
			return (op_many(info, 3, (enum e_op[]){SB, PA, PA}));
	}
	else if (c->loc.pos == BOTTOM)
	{
		if (circ_stack_seek_bottom(&info->b, 0)
			> circ_stack_seek_bottom(&info->b, 1))
			return (op_many(info, 4, (enum e_op[]){RRB, PA, RRB, PA}));
		else
			return (op_many(info, 4, (enum e_op[]){RRB, RRB, PA, PA}));
	}
	else
		return (-EINVAL);
}

int	sort_two(struct s_op_info *info, struct s_chunk *c)
{
	if (c->size != 2)
		return (-EINVAL);
	if (c->loc.id == A)
		return (sort_two_flow_a(info, c));
	else if (c->loc.id == B)
		return (sort_two_flow_b(info, c));
	else
		return (-EINVAL);
}
