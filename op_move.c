/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:34:41 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/15 03:25:54 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "op.h"

#include "stack_loc.h"

#include <errno.h>

static int	op_move_flow_src_a_top(struct s_op_info *info, struct s_stack_loc *dest)
{
	if (dest->id == A && dest->pos == BOTTOM)
		return (op(info, RA));
	if (dest->id == B && dest->pos == TOP)
		return (op(info, PB));
	if (dest->id == B && dest->pos == BOTTOM)
		return (op_many(info, 2, (enum e_op[]){PB, RB}));
	return (0);
}

static int	op_move_flow_src_a_bottom(struct s_op_info *info, struct s_stack_loc *dest)
{
	if (dest->id == A && dest->pos == TOP)
		return (op(info, RRA));
	if (dest->id == B && dest->pos == TOP)
		return (op_many(info, 2, (enum e_op[]){RRA, PB}));
	if (dest->id == B && dest->pos == BOTTOM)
		return (op_many(info, 3, (enum e_op[]){RRA, PB, RB}));
	return (0);
}

static int	op_move_flow_src_b_top(struct s_op_info *info, struct s_stack_loc *dest)
{
	if (dest->id == A && dest->pos == TOP)
		return (op(info, PA));
	if (dest->id == A && dest->pos == BOTTOM)
		return (op_many(info, 3, (enum e_op[]){PA, RA}));
	if (dest->id == B && dest->pos == BOTTOM)
		return (op(info, RB));
	return (0);
}

static int	op_move_flow_src_b_bottom(struct s_op_info *info, struct s_stack_loc *dest)
{
	if (dest->id == A && dest->pos == TOP)
		return (op_many(info, 2, (enum e_op[]){RRB, PA}));
	if (dest->id == A && dest->pos == BOTTOM)
		return (op_many(info, 3, (enum e_op[]){RRB, PA, RA}));
	if (dest->id == B && dest->pos == TOP)
		return (op(info, RRB));
	return (0);
}

int	op_move(struct s_op_info *info, struct s_stack_loc *dest, struct s_stack_loc *src)
{
	int (*func)(struct s_op_info *info, struct s_stack_loc *dest);

	if (ft_memcmp(dest, src, sizeof(*dest)) == 0)
		return (0);
	if (src->id == A && src->pos == TOP)
		func = &op_move_flow_src_a_top;
	else if (src->id == A && src->pos == BOTTOM)
		func = &op_move_flow_src_a_bottom;
	else if (src->id == B && src->pos == TOP)
		func = &op_move_flow_src_b_top;
	else if (src->id == B && src->pos == BOTTOM)
		func = &op_move_flow_src_b_bottom;
	else
		return (-EINVAL);
	return (func(info, dest));
}
