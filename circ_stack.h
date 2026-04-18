/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:27:27 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:39:09 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRC_STACK_H
# define CIRC_STACK_H
# include <stddef.h>

typedef struct s_circ_stack
{
	int		*begin;
	int		*last;
	int		*top;
	int		*bottom;
	size_t	size;
}	t_circ_stack;

size_t	circ_stack_add_strsnums(t_circ_stack *cs, char **strsnums,
			size_t nstr);
void	circ_stack_destroy(t_circ_stack *cs);
int		circ_stack_init(t_circ_stack *cs, size_t size);
int		circ_stack_seek(t_circ_stack *cs, size_t n);
int		circ_stack_seek_bottom(t_circ_stack *cs, size_t n);
void	circ_stack_pop_bottom(t_circ_stack *cs);
void	circ_stack_pop(t_circ_stack *cs);
void	circ_stack_push_bottom(t_circ_stack *cs, int num);
void	circ_stack_push(t_circ_stack *cs, int num);

#endif
