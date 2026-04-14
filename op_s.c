/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 09:02:53 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/14 22:33:39 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int	op_s(t_circ_stack *cs)
{
	int	tmp1;
	int	tmp2;

	if (cs->size < 2)
		return (1);
	tmp1 = *cs->top;
	circ_stack_pop(cs);
	tmp2 = *cs->top;
	circ_stack_pop(cs);
	circ_stack_push(cs, tmp1);
	circ_stack_push(cs, tmp2);
	return (0);
}
