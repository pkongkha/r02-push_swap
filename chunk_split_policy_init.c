/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split_policy_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:31:25 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/15 00:13:15 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "stack_loc.h"

void	chunk_split_policy_init(struct s_chunk_split_policy *pol, struct s_nbr_range *range, struct s_stack_loc *srcloc)
{
	const int	diff = range->max - range->min;

	if (srcloc->id == A)
	{
		if (srcloc->pos == TOP)
			*pol = (struct s_chunk_split_policy){
				.max_to = {.id = A, .pos = BOTTOM},
				.mid_to = {.id = B, .pos = TOP},
				.min_to = {.id = B, .pos = BOTTOM},
			};
		else if (srcloc->pos == BOTTOM)
			*pol = (struct s_chunk_split_policy){
				.max_to = {.id = A, .pos = TOP},
				.mid_to = {.id = B, .pos = TOP},
				.min_to = {.id = B, .pos = BOTTOM},
			};
	}
	else if (srcloc->id == B)
	{
		if (srcloc->pos == TOP)
			*pol = (struct s_chunk_split_policy){
				.max_to = {.id = A, .pos = TOP},
				.mid_to = {.id = A, .pos = BOTTOM},
				.min_to = {.id = B, .pos = BOTTOM},
			};
		else if (srcloc->pos == BOTTOM)
			*pol = (struct s_chunk_split_policy){
				.max_to = {.id = A, .pos = TOP},
				.mid_to = {.id = A, .pos = BOTTOM},
				.min_to = {.id = B, .pos = TOP},
			};
	}
	pol->pivot_min = range->min + diff / 3;
	pol->pivot_mid = range->min + diff / 3 * 2;
}
