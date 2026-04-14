/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_push_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:15:03 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/14 17:57:25 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

void	circ_stack_push_bottom(t_circ_stack *cs, int num)
{
	if (!cs->bottom)
	{
		cs->bottom = cs->begin;
		cs->top = cs->begin;
	}
	else if (cs->bottom == cs->begin)
		cs->bottom = cs->last;
	else
		--cs->bottom;
	*cs->bottom = num;
	++cs->size;
}
