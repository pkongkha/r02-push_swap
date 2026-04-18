/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_flow_a_bottom.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:58:39 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:47:41 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "sort.h"

#include <errno.h>

int	sort_three_flow_a_bottom(struct s_op_info *info)
{
	const int	scheme = sort_three_flow_detect_scheme_bottom(&info->a);

	if (scheme == 123)
		return (op_many(info, 3, (enum e_op[]){RRA, RRA, RRA}));
	else if (scheme == 132)
		return (op_many(info, 4, (enum e_op[]){RRA, RRA, SA, RRA}));
	else if (scheme == 213)
		return (op_many(info, 4, (enum e_op[]){RRA, RRA, RRA, SA}));
	else if (scheme == 231)
		return (op_many(info, 5, (enum e_op[]){RRA, RRA, SA, RRA, SA}));
	else if (scheme == 312)
		return (op_many(info, 7, (enum e_op[]){RRA, RRA, RRA, SA, RA, SA,
				RRA}));
	else if (scheme == 321)
		return (op_many(info, 6, (enum e_op[]){RRA, PB, RRA, RRA, SA, PA}));
	else
		return (-EINVAL);
}
