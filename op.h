/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:44:57 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/19 01:21:57 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H
# include "circ_stack.h"
# include "stack_loc.h"

enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

struct s_op_transaction
{
	enum e_op				op;
	struct s_op_transaction	*next;
};

struct s_op_transaction_info
{
	struct s_op_transaction	*begin;
	struct s_op_transaction	*curr;
};

struct s_op_info
{
	struct s_circ_stack				a;
	struct s_circ_stack				b;
	struct s_op_transaction_info	trinfo;
};

// Each operations returns 0 if succeed, negative errno when error
int			op_many(struct s_op_info *info, size_t count, enum e_op *ops);
int			op_move(struct s_op_info *info, struct s_stack_loc *dest,
				struct s_stack_loc *src);
int			op(struct s_op_info *info, enum e_op op);
int			op_p(t_circ_stack *dst, t_circ_stack *src);
int			op_r(t_circ_stack *cs);
int			op_rr(t_circ_stack *cs);
int			op_s(t_circ_stack *cs);
void		op_transaction_destroy(struct s_op_transaction_info *trinfo);
int			op_transaction_record(struct s_op_transaction_info *trinfo,
				enum e_op op);
void		op_transaction_print(struct s_op_transaction_info *trinfo);
const char	*op_obtain_enum_string(enum e_op op);
int			op_transaction_opti(struct s_op_transaction_info *trinfo);

#endif
