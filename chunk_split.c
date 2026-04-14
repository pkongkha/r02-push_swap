/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:32:33 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/15 00:08:11 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "op.h"

void	chunk_split(struct s_op_info *info, struct s_chunk_split_result *res, struct s_chunk *chunk)
{
	int nbr;

	*res = (struct s_chunk_split_result){.move_max = 0, .move_mid = 0, .move_min = 0};
	chunk_split_policy_init(&res->pol, &chunk->nbrrange, &chunk->loc);
	while (chunk->size != 0)
	{
		nbr = chunk_split_get_next_memb(&info->a, &info->b, &chunk->loc);
		if (nbr <= res->pol.pivot_min)
		{
			op_move(info, &res->pol.min_to, &chunk->loc);
			++res->move_min;
		}
		else if (nbr <= res->pol.pivot_mid)
		{
			op_move(info, &res->pol.mid_to, &chunk->loc);
			++res->move_mid;
		}
		else
		{
			op_move(info, &res->pol.max_to, &chunk->loc);
			++res->move_max;
		}
		--chunk->size;
	}
}
