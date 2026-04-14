/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_flow_a_top.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 16:57:21 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/15 02:13:12 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "sort.h"

#include <errno.h>

int sort_three_flow_a_top(struct s_op_info *info)
{
	int scheme = sort_three_flow_detect_scheme_top(&info->a);

	if (scheme == 123)
		return (0);
	else if (scheme == 132)
		return (op_many(info, 3, (enum e_op[]){RA, SA, RRA}));
	else if (scheme == 213)
		return (op_many(info, 1, (enum e_op[]){SA}));
	else if (scheme == 231)
		return (op_many(info, 4, (enum e_op[]){RA, SA, RRA, SA}));
	else if (scheme == 312)
		return (op_many(info, 4, (enum e_op[]){SA, RA, SA, RRA}));
	else if (scheme == 321)
		return (op_many(info, 5, (enum e_op[]){SA, RA, SA, RRA, SA}));
	else
	 	return (-EINVAL);
}
