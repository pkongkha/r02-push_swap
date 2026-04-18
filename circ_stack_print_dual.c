/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_print_dual.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:15:51 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 12:16:11 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "circ_stack.h"

void circ_stack_print_dual(t_circ_stack *a, t_circ_stack *b)
{
	size_t i;

	i = 0;
	while (i < a->size || i < b->size)
	{
		if (i < a->size)
			ft_printf("%3d ", circ_stack_seek(a, i));
		else
		 	ft_printf("    ");
		if (i < b->size)
			ft_printf("%3d ", circ_stack_seek(b, i));
		ft_printf("\n");
		++i;
	}
	ft_printf("\n");
}


