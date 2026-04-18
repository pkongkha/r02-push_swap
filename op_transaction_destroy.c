/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_transaction_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:46:56 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 11:47:54 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

#include <stdlib.h>

void	op_transaction_destroy(struct s_op_transaction_info *trinfo)
{
	struct s_op_transaction	*prev;

	while (trinfo->begin)
	{
		prev = trinfo->begin;
		trinfo->begin = trinfo->begin->next;
		free(prev);
	}
	trinfo->begin = NULL;
	trinfo->curr = NULL;
}
