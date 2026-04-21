/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_transaction_opti.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 20:08:07 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/19 01:20:07 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include <stdlib.h>

#include "errno.h"

static int	op_transaction_opti_redundant(struct s_op_transaction_info *trinfo)
{
	struct s_op_transaction	*curr;
	struct s_op_transaction	*prev;

	curr = trinfo->begin;
	while (curr && curr->next)
	{
		if ((curr->op == curr->next->op && (curr->op == SA || curr->op == SB))
			|| (curr->op == RA && curr->next->op == RRA)
			|| (curr->op == RRA && curr->next->op == RA)
			|| (curr->op == RB && curr->next->op == RRB)
			|| (curr->op == RRB && curr->next->op == RB)
		)
		{
			if (curr == trinfo->begin || curr->next == trinfo->begin)
				trinfo->begin = curr->next->next;
			if (prev)
				prev->next = curr->next->next;
			free(curr->next);
			free(curr);
			return (-EAGAIN);
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}

static int	op_transaction_opti_combination_combiner(
	struct s_op_transaction *curr, enum e_op op)
{
	struct s_op_transaction	*to_delete;

	to_delete = curr->next;
	curr->next = curr->next->next;
	free(to_delete);
	curr->op = op;
	return (-EAGAIN);
}

static int	op_transaction_opti_combination(
	struct s_op_transaction_info *trinfo)
{
	struct s_op_transaction	*curr;

	curr = trinfo->begin;
	while (curr && curr->next)
	{
		if ((curr->op == SA && curr->next->op == SB)
			|| (curr->op == SB && curr->next->op == SA))
			return (op_transaction_opti_combination_combiner(curr, SS));
		else if ((curr->op == RA && curr->next->op == RB)
			|| (curr->op == RB && curr->next->op == RA))
			return (op_transaction_opti_combination_combiner(curr, RR));
		else if ((curr->op == RRA && curr->next->op == RRB)
			|| (curr->op == RRB && curr->next->op == RRA))
			return (op_transaction_opti_combination_combiner(curr, RRR));
		curr = curr->next;
	}
	return (0);
}

int	op_transaction_opti(struct s_op_transaction_info *trinfo)
{
	int	status;

	if (!trinfo->begin || !trinfo->begin->next)
		return (0);
	status = -EAGAIN;
	while (status == -EAGAIN)
		status = op_transaction_opti_redundant(trinfo);
	while (status == -EAGAIN)
		status = op_transaction_opti_combination(trinfo);
	return (status);
}
