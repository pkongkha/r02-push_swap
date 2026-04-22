/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 22:30:07 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/22 17:45:32 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "validate.h"
#include "word_count.h"
#include "op.h"
#include "circ_stack.h"

#include <libft.h>

#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

static void	cleanup(struct s_op_info *info, char *gnl_buf)
{
	if (info->a.begin)
		circ_stack_destroy(&info->a);
	if (info->b.begin)
		circ_stack_destroy(&info->b);
	if (gnl_buf)
	{
		free(gnl_buf);
		while (1)
		{
			gnl_buf = get_next_line(STDIN_FILENO);
			if (gnl_buf)
				free(gnl_buf);
			else
				break ;
		}
	}
}

static int	parseargs(struct s_op_info *info, char **strsnums, size_t nstr)
{
	const int	num_total = word_count_from_strsnums(strsnums, nstr);

	if (num_total == 0)
		return (cleanup(info, NULL), -EINVAL);
	if (circ_stack_init(&info->a, num_total) < 0)
		return (cleanup(info, NULL), -ENOMEM);
	if (circ_stack_init(&info->b, num_total) < 0)
		return (cleanup(info, NULL), -ENOMEM);
	if (circ_stack_add_strsnums(&info->a, strsnums, nstr) != num_total)
		return (cleanup(info, NULL), -EINVAL);
	return (0);
}

static int	print_errmsg(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (1);
}

static int	do_op(t_circ_stack *a, t_circ_stack *b, char *op_str)
{
	if ((!ft_strncmp(op_str, "sa\n", 4) && !op_s(a))
		|| (!ft_strncmp(op_str, "sb\n", 4) && !op_s(b))
		|| (!ft_strncmp(op_str, "ss\n", 4) && !op_s(a) && !op_s(b))
		|| (!ft_strncmp(op_str, "pa\n", 4) && !op_p(a, b))
		|| (!ft_strncmp(op_str, "pb\n", 4) && !op_p(b, a))
		|| (!ft_strncmp(op_str, "ra\n", 4) && !op_r(a))
		|| (!ft_strncmp(op_str, "rb\n", 4) && !op_r(b))
		|| (!ft_strncmp(op_str, "rr\n", 4) && !op_r(a) && !op_r(b))
		|| (!ft_strncmp(op_str, "rra\n", 5) && !op_rr(a))
		|| (!ft_strncmp(op_str, "rrb\n", 5) && !op_rr(b))
		|| (!ft_strncmp(op_str, "rrr\n", 5) && !op_rr(a) && !op_rr(b))
	)
		return (0);
	else
		return (-EINVAL);
}

int	main(int argc, char **argv)
{
	struct s_op_info	info;
	char				*str;

	if (argc < 2)
		return (0);
	info = (struct s_op_info){0};
	if (parseargs(&info, argv + 1, argc - 1))
		return (print_errmsg(), 1);
	if (validate_duplicate(&info.a))
		return (cleanup(&info, NULL), print_errmsg(), 1);
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str)
			break ;
		if (do_op(&info.a, &info.b, str) == -EINVAL)
			return (cleanup(&info, str), print_errmsg(), 1);
		free(str);
	}
	if (info.b.size == 0 && validate_sorted(&info))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	cleanup(&info, NULL);
	return (0);
}
