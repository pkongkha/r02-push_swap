/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:50:03 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/21 15:28:13 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "sort.h"
#include "validate.h"
#include "word_count.h"

#include <errno.h>
#include <limits.h>
#include <libft.h>
#include <stddef.h>
#include <unistd.h>

static int	print_errmsg(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (1);
}

void	cleanup(struct s_op_info *info)
{
	if (info->a.begin)
		circ_stack_destroy(&info->a);
	if (info->b.begin)
		circ_stack_destroy(&info->b);
	if (info->trinfo.begin)
		op_transaction_destroy(&info->trinfo);
}

int	parseargs(struct s_op_info *info, char **strsnums, size_t nstr)
{
	const size_t	num_total = word_count_from_strsnums(strsnums, nstr);

	if (num_total == 0)
		return (cleanup(info), -EINVAL);
	if (circ_stack_init(&info->a, num_total) < 0)
		return (cleanup(info), -ENOMEM);
	if (circ_stack_init(&info->b, num_total) < 0)
		return (cleanup(info), -ENOMEM);
	if (circ_stack_add_strsnums(&info->a, strsnums, nstr) != num_total)
		return (cleanup(info), -EINVAL);
	return (0);
}

int	sort_optimized(struct s_op_info *info)
{
	if (info->a.size == 3)
		return (sort_dumb_three(info));
	else if (info->a.size == 5)
		return (sort_dumb_five(info));
	else
		return (sort(info,
				&(struct s_chunk){
				.loc = {.id = A, .pos = TOP},
				.size = info->a.size}
		));
}

int	main(int argc, char **argv)
{
	struct s_op_info	info;

	if (argc < 2)
		return (print_errmsg(), 1);
	info = (struct s_op_info){0};
	if (parseargs(&info, argv + 1, argc - 1))
		return (print_errmsg(), 1);
	if (validate_duplicate(&info.a))
		return (cleanup(&info), print_errmsg(), 1);
	if (validate_sorted(&info))
		return (cleanup(&info), print_errmsg(), 1);
	if (sort_optimized(&info))
		return (cleanup(&info), print_errmsg(), 1);
	if (op_transaction_opti(&info.trinfo))
		return (cleanup(&info), print_errmsg(), 1);
	op_transaction_print(&info.trinfo);
	cleanup(&info);
	return (0);
}
