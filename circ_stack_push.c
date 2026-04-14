/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 23:06:06 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/14 17:57:13 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

void	circ_stack_push(t_circ_stack *cs, int num)
{
	if (!cs->top)
	{
		cs->top = cs->begin;
		cs->bottom = cs->begin;
	}
	else if (cs->top == cs->last)
		cs->top = cs->begin;
	else
		++cs->top;
	*cs->top = num;
	++cs->size;
}
