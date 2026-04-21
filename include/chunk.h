/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:29:23 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/19 01:23:56 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNK_H
# define CHUNK_H
# include "stack_loc.h"
# include "circ_stack.h"
# include "op.h"

# include <stddef.h>

struct	s_nbr_range
{
	int	min;
	int	max;
};

struct	s_chunk
{
	struct s_stack_loc	loc;
	size_t				size;
	struct s_nbr_range	nbrrange;
};

struct	s_chunk_split_policy
{
	struct s_stack_loc	min_to;
	struct s_stack_loc	mid_to;
	struct s_stack_loc	max_to;
	int					pivot_min;
	int					pivot_mid;
};

struct s_chunk_split_result
{
	struct s_chunk_split_policy	pol;
	size_t						move_min;
	size_t						move_mid;
	size_t						move_max;
};

int		chunk_find_max(struct s_op_info *info, struct s_chunk *chunk);
int		chunk_find_min(struct s_op_info *info, struct s_chunk *chunk);
void	chunk_split(struct s_op_info *info, struct s_chunk_split_result *res,
			struct s_chunk *chunk);
int		chunk_split_get_next_memb(struct s_circ_stack *a,
			struct s_circ_stack *b, struct s_stack_loc *loc);
void	chunk_split_policy_init(struct s_chunk_split_policy *pol,
			struct s_chunk *ch);
#endif
