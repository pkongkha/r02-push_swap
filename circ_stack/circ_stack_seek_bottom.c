/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_seek_bottom.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 00:57:03 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/14 22:12:51 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

int	circ_stack_seek_bottom(t_circ_stack *cs, size_t n)
{
	int	*p;

	p = cs->bottom + n;
	if (p > cs->last)
		p = cs->begin + (p - cs->last) - 1;
	return (*p);
}
