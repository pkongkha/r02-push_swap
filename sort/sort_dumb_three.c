/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dumb_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 01:08:03 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/21 15:26:19 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "validate.h"

int	sort_dumb_three(struct s_op_info *info)
{
	int	status;

	while (!validate_sorted(info))
	{
		if (circ_stack_seek(&info->a, 0) > circ_stack_seek(&info->a, 1))
			status = op(info, SA);
		else
			status = op(info, RRA);
		if (status)
			return (status);
	}
	return (0);
}
