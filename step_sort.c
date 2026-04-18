/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 22:49:54 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/19 01:23:41 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "circ_stack.h"
#include "op.h"
#include "sort.h"
#include "step.h"

int	step_sort(struct s_op_info *info)
{
	if (info->a.size == 3)
		return (sort_dumb_three(info));
	else if (info->a.size == 5)
		return (sort_dumb_five(info));
	else
		return (sort(info,
				&(struct s_chunk){
				.loc = {.id = A, .pos = TOP},
				.size = info->a.size}
		));
}
