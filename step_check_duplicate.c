/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_check_duplicate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:55:02 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:42:07 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

int	step_check_duplicate(struct s_circ_stack *cs)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cs->size)
	{
		j = i + 1;
		while (j < cs->size)
		{
			if (circ_stack_seek(cs, i) == circ_stack_seek(cs, j))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}
