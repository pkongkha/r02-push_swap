/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_seek.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:50:51 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/14 22:14:17 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

int	circ_stack_seek(t_circ_stack *cs, size_t n)
{
	int	*p;

	p = cs->top - n;
	if (p < cs->begin)
		p = cs->last - (cs->begin - p) + 1;
	return (*p);
}
