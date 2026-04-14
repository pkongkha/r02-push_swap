/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_base_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:52:22 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/15 03:19:43 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "chunk.h"
#include "op.h"

#include <errno.h>

void circ_stack_print_dual(t_circ_stack *a, t_circ_stack *b);

// Impl: Everything should be thrown to A TOP in sorted manner
//      Which means, the largest one should be sent first,
//      and the least should be sent last
int sort_base_case(struct s_op_info *info, struct s_chunk *c)
{
	int (*sort_func)(struct s_op_info *info, struct s_chunk *c);

	if (c->size == 1)
		sort_func = &sort_one;
	else if (c->size == 2)
		sort_func = &sort_two;
	else if (c->size == 3)
		sort_func = &sort_three;
	else
		return (-EINVAL);
	return(sort_func(info, c));
}
