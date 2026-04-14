/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_loc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:28:37 by pkongkha          #+#    #+#             */
/*   Updated: 2026/03/18 15:28:48 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_LOC_H
# define STACK_LOC_H

enum	e_stack_pos {
	TOP,
	BOTTOM
};

enum	e_stack_id {
	A,
	B
};

struct s_stack_loc {
	enum e_stack_pos	pos;
	enum e_stack_id		id;
};
#endif
