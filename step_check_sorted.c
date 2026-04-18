/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_check_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 21:42:00 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/19 01:20:21 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"
#include "op.h"

#include <limits.h>
#include <stddef.h>

int	step_check_sorted(struct s_op_info *info)
{
	size_t	i;
	int		num;

	i = 0;
	num = INT_MIN;
	while (i < info->a.size)
	{
		if (num > circ_stack_seek(&info->a, i))
			return (0);
		num = circ_stack_seek(&info->a, i);
		++i;
	}
	return (1);
}
