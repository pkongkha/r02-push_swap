/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:55:40 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 11:55:58 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"
#include "op.h"

void	step_cleanup(struct s_op_info *info)
{
	if (info->a.begin)
		circ_stack_destroy(&info->a);
	if (info->b.begin)
		circ_stack_destroy(&info->b);
	if (info->trinfo.begin)
		op_transaction_destroy(&info->trinfo);
}
