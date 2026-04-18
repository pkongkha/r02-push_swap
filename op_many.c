/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_many.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:18:22 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:54:43 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int	op_many(struct s_op_info *info, size_t count, enum e_op *ops)
{
	int	status;

	while (count)
	{
		status = op(info, *ops);
		if (status)
			return (status);
		++ops;
		--count;
	}
	return (0);
}
