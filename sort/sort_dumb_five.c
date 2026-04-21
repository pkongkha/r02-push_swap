/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dumb_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 01:08:56 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/19 01:21:36 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

#include <errno.h>

static int	push_smallest_test(struct s_op_info *info, int min, int i)
{
	int	status;

	if (circ_stack_seek(&info->a, i) == min)
	{
		while (i-- > 0)
		{
			status = op(info, RA);
			if (status)
				return (status);
		}
		return (op(info, PB));
	}
	if (circ_stack_seek_bottom(&info->a, i) == min)
	{
		while (i-- >= 0)
		{
			status = op(info, RRA);
			if (status)
				return (status);
		}
		return (op(info, PB));
	}
	return (-EAGAIN);
}

static int	push_smallest(struct s_op_info *info)
{
	int	min;
	int	status;
	int	i;

	min = chunk_find_min(info, &(struct s_chunk){.loc = {.id = A, .pos = TOP},
			.size = info->a.size});
	i = 0;
	status = -EAGAIN;
	while (status == -EAGAIN)
	{
		status = push_smallest_test(info, min, i);
		++i;
	}
	return (status);
}

int	sort_dumb_five(struct s_op_info *info)
{
	push_smallest(info);
	push_smallest(info);
	sort_dumb_three(info);
	sort_two(info, &(struct s_chunk){.loc = {.id = B, .pos = TOP}, .size = 2});
	return (0);
}
