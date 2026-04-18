/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:58:18 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 12:00:08 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "chunk.h"
#include "sort.h"

int	sort(struct s_op_info *info, struct s_chunk *chunk)
{
	int status;
	struct s_chunk_split_result res;

	if (chunk->size == 0)
		return (0);
	chunk->nbrrange.min = chunk_find_min(info, chunk);
	chunk->nbrrange.max = chunk_find_max(info, chunk);
	// ft_printf("CHUNK: %s %s (%d - %d), %d\n", chunk->loc.pos == TOP ? "TOP" : "BOTTOM", chunk->loc.id == A ? "A" : "B", chunk->nbrrange.max, chunk->nbrrange.min, chunk->size);
	// circ_stack_print_dual(&info->a, &info->b);
	if (chunk->size <= 3)
		return (sort_base_case(info, chunk));
	chunk_split(info, &res, chunk);
	status = sort(info, &(struct s_chunk){
		.loc = res.pol.max_to,
		.size = res.move_max});
	if (status)
		return (status);
	status = sort(info, &(struct s_chunk){
		.loc = res.pol.mid_to,
		.size = res.move_mid});
	if (status)
		return (status);
	status = sort(info, &(struct s_chunk){
		.loc = res.pol.min_to,
		.size = res.move_min});
	if (status)
		return (status);
	return (0);
}
