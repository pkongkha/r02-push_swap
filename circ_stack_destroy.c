/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:06:27 by pkongkha          #+#    #+#             */
/*   Updated: 2026/03/18 15:07:41 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

#include <stdlib.h>

void	circ_stack_destroy(t_circ_stack *cs)
{
	if (cs->begin)
		free(cs->begin);
	cs->begin = NULL;
	cs->last = NULL;
	cs->top = NULL;
	cs->bottom = NULL;
}
