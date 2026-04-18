/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_transaction_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:48:32 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 11:52:03 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

#include <libft.h>

void	op_transaction_print(struct s_op_transaction_info *trinfo)
{
	trinfo->curr = trinfo->begin;
	while (trinfo->curr)
	{
		ft_printf("%s\n", op_obtain_enum_string(trinfo->curr->op));
		trinfo->curr = trinfo->curr->next;
	};
}
