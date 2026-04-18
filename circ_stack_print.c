/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:14:59 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 12:15:32 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "circ_stack.h"

void circ_stack_print(t_circ_stack *cs)
{
	size_t i;

	i = 0;
	while (i < cs->size)
	{
		ft_printf("%d ", circ_stack_seek(cs, i));
		++i;
	}
}
