/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 01:45:39 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/14 22:32:45 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

#include <errno.h>

int	op_rr(t_circ_stack *cs)
{
	int	num;

	if (cs->size < 1)
		return (-EINVAL);
	if (cs->size > 1)
	{
		num = *cs->bottom;
		circ_stack_pop_bottom(cs);
		circ_stack_push(cs, num);
	}
	return (0);
}
