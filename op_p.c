/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 22:09:45 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:52:47 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "circ_stack.h"

int	op_p(t_circ_stack *dst, t_circ_stack *src)
{
	if (src->size == 0)
		return (1);
	circ_stack_push(dst, *src->top);
	circ_stack_pop(src);
	return (0);
}
