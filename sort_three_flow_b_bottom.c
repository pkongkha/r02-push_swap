/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_flow_b_bottom.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:52:35 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/15 01:51:13 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "sort.h"

#include <errno.h>

int sort_three_flow_b_bottom(struct s_op_info *info)
{
	int scheme = sort_three_flow_detect_scheme_bottom(&info->b);

	if (scheme == 123)
		return (op_many(info, 6, (enum e_op[]){RRB, PA, RRB, PA, RRB, PA}));
	else if (scheme == 132)
		return (op_many(info, 6, (enum e_op[]){RRB, RRB, PA, PA, RRB, PA}));
	else if (scheme == 213)
		return (op_many(info, 6, (enum e_op[]){RRB, PA, RRB, RRB, PA, PA}));
	else if (scheme == 231)
		return (op_many(info, 6, (enum e_op[]){RRB, RRB, PA, RRB, PA, PA}));
	else if (scheme == 312)
		return (op_many(info, 7, (enum e_op[]){RRB, RRB, RRB, PA, PA, PA, SA}));
	else if (scheme == 321)
		return (op_many(info, 6, (enum e_op[]){RRB, RRB, RRB, PA, PA, PA}));
	else
	 	return (-EINVAL);
}
