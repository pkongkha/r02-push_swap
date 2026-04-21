/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 21:42:00 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/21 15:27:13 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validate.h"
#include "circ_stack.h"
#include "op.h"

#include <limits.h>
#include <stddef.h>

int	validate_sorted(struct s_op_info *info)
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
