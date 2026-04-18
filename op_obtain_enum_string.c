/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_obtain_enum_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:49:20 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 11:49:44 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

const char *op_obtain_enum_string(enum e_op op)
{
	static const char *kv[] = {
		[SA] = "sa",
		[SB] = "sb",
		[SS] = "ss",
		[PA] = "pa",
		[PB] = "pb",
		[RA] = "ra",
		[RB] = "rb",
		[RR] = "rr",
		[RRA] = "rra",
		[RRB] = "rrb",
		[RRR] = "rrr"
	};
	return (kv[op]);
}
