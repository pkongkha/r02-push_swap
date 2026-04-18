/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:57:36 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:43:43 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	step_sort(struct s_op_info *info)
{
	return (sort(info,
			&(struct s_chunk){
			.loc = {.id = A, .pos = TOP},
			.size = info->a.size}
	));
}
