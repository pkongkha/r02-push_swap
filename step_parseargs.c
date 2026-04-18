/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_parseargs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:53:21 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 12:13:32 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "step.h"
#include "word_count.h"

#include <errno.h>

int	step_parseargs(struct s_op_info *info, char **strsnums, size_t nstr)
{
	const size_t	num_total = word_count_from_strsnums(strsnums, nstr);

	if (num_total == 0)
		return (step_cleanup(info), -EINVAL);
	if (circ_stack_init(&info->a, num_total) < 0)
		return (step_cleanup(info), -ENOMEM);
	if (circ_stack_init(&info->b, num_total) < 0)
		return (step_cleanup(info), -ENOMEM);
	if (circ_stack_add_strsnums(&info->a, strsnums, nstr) != num_total)
		return (step_cleanup(info), -EINVAL);
	return (0);
}
