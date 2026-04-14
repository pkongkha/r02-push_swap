/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_pop_bottom.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:22:12 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/14 17:57:41 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

void	circ_stack_pop_bottom(t_circ_stack *cs)
{
	if (cs->bottom == cs->top)
	{
		cs->bottom = NULL;
		cs->top = NULL;
	}
	else if (cs->bottom == cs->last)
		cs->bottom = cs->begin;
	else
		++cs->bottom;
	--cs->size;
}
