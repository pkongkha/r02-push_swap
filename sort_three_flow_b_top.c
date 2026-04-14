/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_flow_b_top.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:57:58 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/15 01:53:39 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "sort.h"

#include <errno.h>

int sort_three_flow_b_top(struct s_op_info *info)
{
	int scheme = sort_three_flow_detect_scheme_top(&info->b);

	if (scheme == 123)
		return (op_many(info, 6, (enum e_op[]){RB, SB, PA, PA, RRB, PA}));
	else if (scheme == 132)
		return (op_many(info, 5, (enum e_op[]){PA, PA, SA, PA, SA}));
	else if (scheme == 213)
		return (op_many(info, 5, (enum e_op[]){PA, SB, PA, SA, PA}));
	else if (scheme == 231)
		return (op_many(info, 4, (enum e_op[]){SB, PA, PA, PA}));
	else if (scheme == 312)
		return (op_many(info, 4, (enum e_op[]){PA, SB, PA, PA}));
	else if (scheme == 321)
		return (op_many(info, 3, (enum e_op[]){PA, PA, PA}));
	else
	 	return (-EINVAL);
}
