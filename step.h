/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:07:52 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 12:13:01 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STEP_H
# define STEP_H
# include "op.h"
# include "stddef.h"

int	step_check_duplicate(struct s_circ_stack *cs);
void	step_cleanup(struct s_op_info *info);
int	step_parseargs(struct s_op_info *info, char **strsnums, size_t nstr);
int	step_sort(struct s_op_info *info);
#endif