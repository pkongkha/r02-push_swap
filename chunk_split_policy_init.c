/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split_policy_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:31:25 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 21:40:13 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chunk.h"
#include "stack_loc.h"

static void	chunk_split_policy_init_a(struct s_chunk_split_policy *pol,
	struct s_stack_loc *srcloc)
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

static void	chunk_split_policy_init_b(struct s_chunk_split_policy *pol,
	struct s_stack_loc *srcloc)
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

void	chunk_split_policy_init(struct s_chunk_split_policy *pol,
	struct s_chunk *ch)
{
	const int	diff = ch->nbrrange.max - ch->nbrrange.min;

	if (ch->loc.id == A)
		chunk_split_policy_init_a(pol, &ch->loc);
	else if (ch->loc.id == B)
		chunk_split_policy_init_b(pol, &ch->loc);
	pol->pivot_min = ch->nbrrange.min + diff / 2.71 / 2;
	pol->pivot_mid = ch->nbrrange.min + diff / 2;
}
