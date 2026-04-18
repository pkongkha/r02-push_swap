/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:50:03 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/18 13:51:07 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "step.h"

#include <limits.h>
#include <libft.h>
#include <stddef.h>
#include <unistd.h>

static int	print_errmsg(void)
{
	write(STDERR_FILENO, "Error", 5);
	return (1);
}

int	main(int argc, char **argv)
{
	struct s_op_info	info;

	if (argc < 2)
		return (print_errmsg(), 1);
	info = (struct s_op_info){0};
	if (step_parseargs(&info, argv + 1, argc - 1))
		return (print_errmsg(), 1);
	if (step_check_duplicate(&info.a))
		return (step_cleanup(&info), print_errmsg(), 1);
	if (step_sort(&info))
		return (step_cleanup(&info), print_errmsg(), 1);
	op_transaction_print(&info.trinfo);
	step_cleanup(&info);
	return (0);
}
