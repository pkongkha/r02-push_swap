/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:53:19 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:35:21 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "chunk.h"
# include "op.h"

int	sort(struct s_op_info *info, struct s_chunk *chunk);
int	sort_one(struct s_op_info *info, struct s_chunk *c);
int	sort_two(struct s_op_info *info, struct s_chunk *c);
int	sort_three(struct s_op_info *info, struct s_chunk *c);
int	sort_three_flow_a_top(struct s_op_info *info);
int	sort_three_flow_a_bottom(struct s_op_info *info);
int	sort_three_flow_b_top(struct s_op_info *info);
int	sort_three_flow_b_bottom(struct s_op_info *info);
int	sort_three_flow_detect_scheme_top(struct s_circ_stack *cs);
int	sort_three_flow_detect_scheme_bottom(struct s_circ_stack *cs);
int	sort_base_case(struct s_op_info *info, struct s_chunk *c);
#endif
