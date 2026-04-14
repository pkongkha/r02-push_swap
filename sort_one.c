/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:58:45 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/13 21:09:02 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "chunk.h"
#include "op.h"

#include <errno.h>

int sort_one(struct s_op_info *info, struct s_chunk *c)
{
	if (c->size != 1)
		return (-EINVAL);
	return (op_move(info, &(struct s_stack_loc){ .id = A, .pos = TOP }, &c->loc));
}
