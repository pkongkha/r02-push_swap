/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:47:33 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:56:32 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"
#include <errno.h>
#include <stdlib.h>

int	circ_stack_init(t_circ_stack *cs, size_t size)
{
	cs->begin = malloc(sizeof(*cs->begin) * size);
	if (!cs->begin)
		return (-ENOMEM);
	cs->last = cs->begin + size - 1;
	cs->top = NULL;
	cs->bottom = NULL;
	cs->size = 0;
	return (0);
}
