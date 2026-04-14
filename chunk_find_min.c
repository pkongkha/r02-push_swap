/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_find_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 02:42:26 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/15 02:49:16 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"
#include "op.h"
#include "chunk.h"

#include <libft.h>

#include <limits.h>

int chunk_find_min(struct s_op_info *info, struct s_chunk *chunk)
{
	size_t i;
	int		minnbr;

	i = 0;
	minnbr = INT_MAX;
	while (i < chunk->size)
	{
		if (chunk->loc.id == A)
		{
			if (chunk->loc.pos == TOP)
				minnbr = ft_min(minnbr, circ_stack_seek(&info->a, i));
			else if (chunk->loc.pos == BOTTOM)
				minnbr = ft_min(minnbr, circ_stack_seek_bottom(&info->a, i));
		}
		else if (chunk->loc.id == B)
		{
			if (chunk->loc.pos == TOP)
				minnbr = ft_min(minnbr, circ_stack_seek(&info->b, i));
			else if (chunk->loc.pos == BOTTOM)
				minnbr = ft_min(minnbr, circ_stack_seek_bottom(&info->b, i));
		}
		++i;
	}
	return (minnbr);
}
