/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:50:03 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/15 03:53:27 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "op.h"
#include "circ_stack.h"
#include "word_count.h"
#include "chunk.h"
#include "sort.h"
#include "stack_loc.h"

#include <limits.h>
#include <libft.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static int	print_errmsg()
{
	write(STDERR_FILENO, "Error", 5);
	return (1);
}

void	op_transaction_destroy(struct s_op_transaction_info *trinfo)
{
	struct s_op_transaction	*prev;

	while (trinfo->begin)
	{
		prev = trinfo->begin;
		trinfo->begin = trinfo->begin->next;
		free(prev);
	}
	trinfo->begin = NULL;
	trinfo->curr = NULL;
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

int	step_parseargs(struct s_op_info *info, char **strsnums, size_t nstr)
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

int	step_check_duplicate(struct s_circ_stack *cs)
{
	size_t i;
	size_t j;

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

int	sort(struct s_op_info *info, struct s_chunk *chunk)
{
	int status;
	struct s_chunk_split_result res;

	if (chunk->size == 0)
		return (0);
	chunk->nbrrange.min = chunk_find_min(info, chunk);
	chunk->nbrrange.max = chunk_find_max(info, chunk);
	ft_printf("CHUNK: %s %s (%d - %d), %d\n", chunk->loc.pos == TOP ? "TOP" : "BOTTOM", chunk->loc.id == A ? "A" : "B", chunk->nbrrange.max, chunk->nbrrange.min, chunk->size);
	circ_stack_print_dual(&info->a, &info->b);
	if (chunk->size <= 3)
		return (sort_base_case(info, chunk));
	chunk_split(info, &res, chunk);
	status = sort(info, &(struct s_chunk){
		.loc = res.pol.max_to,
		.size = res.move_max});
	if (status)
		return (status);
	status = sort(info, &(struct s_chunk){
		.loc = res.pol.mid_to,
		.size = res.move_mid});
	if (status)
		return (status);
	status = sort(info, &(struct s_chunk){
		.loc = res.pol.min_to,
		.size = res.move_min});
	if (status)
		return (status);
	return (0);
}

int	step_sort(struct s_op_info *info)
{
	return (sort(info,
		&(struct s_chunk){
			.loc = {.id = A, .pos = TOP},
			.size = info->a.size}
	));
}

static const char *op_obtain_enum_string(enum e_op op)
{
	static const char *kv[] = {
		[SA] = "sa",
		[SB] = "sb",
		[SS] = "ss",
		[PA] = "pa",
		[PB] = "pb",
		[RA] = "ra",
		[RB] = "rb",
		[RR] = "rr",
		[RRA] = "rra",
		[RRB] = "rrb",
		[RRR] = "rrr"
	};
	return (kv[op]);
}

void	op_transaction_print(struct s_op_transaction_info *trinfo)
{
	trinfo->curr = trinfo->begin;
	while (trinfo->curr)
	{
		ft_printf("%s\n", op_obtain_enum_string(trinfo->curr->op));
		trinfo->curr = trinfo->curr->next;
	};
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
		return (cleanup(&info), print_errmsg(), 1);
	if (step_sort(&info))
		return (cleanup(&info), print_errmsg(), 1);
	op_transaction_print(&info.trinfo);
	cleanup(&info);
	return (0);
}
