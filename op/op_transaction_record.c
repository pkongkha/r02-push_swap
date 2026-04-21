/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_transaction_record.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:50:00 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:51:40 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

#include <errno.h>
#include <stdlib.h>

int	op_transaction_record(struct s_op_transaction_info *trinfo, enum e_op op)
{
	struct s_op_transaction *const	tr = malloc(sizeof(*tr));

	if (!tr)
		return (-ENOMEM);
	tr->op = op;
	tr->next = NULL;
	if (!trinfo->begin)
		trinfo->begin = tr;
	if (trinfo->curr)
		trinfo->curr->next = tr;
	trinfo->curr = tr;
	return (0);
}
