/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 22:15:06 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/14 22:33:07 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"
#include "op.h"

#include <errno.h>

int	op_r(t_circ_stack *cs)
{
	int	num;

	if (cs->size < 1)
		return (-EINVAL);
	if (cs->size > 1)
	{
		num = *cs->top;
		circ_stack_pop(cs);
		circ_stack_push_bottom(cs, num);
	}
	return (0);
}
