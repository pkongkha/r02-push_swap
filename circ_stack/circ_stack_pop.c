/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:06:45 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/14 17:57:33 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

void	circ_stack_pop(t_circ_stack *cs)
{
	if (cs->top == cs->bottom)
	{
		cs->top = NULL;
		cs->bottom = NULL;
	}
	else if (cs->top == cs->begin)
		cs->top = cs->last;
	else
		--cs->top;
	--cs->size;
}
