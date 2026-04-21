/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 04:07:55 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/19 01:23:24 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

#include <errno.h>

static int	do_op(struct s_op_info *info, enum e_op op)
{
	int	op_status;

	if (op == SA)
		op_status = op_s(&info->a);
	else if (op == SB)
		op_status = op_s(&info->b);
	else if (op == PA)
		op_status = op_p(&info->a, &info->b);
	else if (op == PB)
		op_status = op_p(&info->b, &info->a);
	else if (op == RA)
		op_status = op_r(&info->a);
	else if (op == RB)
		op_status = op_r(&info->b);
	else if (op == RRA)
		op_status = op_rr(&info->a);
	else if (op == RRB)
		op_status = op_rr(&info->b);
	else if (op == SS || op == RR || op == RRR)
		return (-ENOSYS);
	else
		return (-EINVAL);
	return (op_status);
}

int	op(struct s_op_info *info, enum e_op op)
{
	const int	op_status = do_op(info, op);

	if (op_status == -EALREADY)
		return (0);
	else if (op_status == 0)
		return (op_transaction_record(&info->trinfo, op));
	return (op_status);
}
