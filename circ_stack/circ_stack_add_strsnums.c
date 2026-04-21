/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circ_stack_add_strsnums.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:08:18 by pkongkha          #+#    #+#             */
/*   Updated: 2026/04/21 17:34:47 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circ_stack.h"

#include <errno.h>
#include <libft.h>
#include <stddef.h>
#include <stdlib.h>

static int	validate_int_overflow(char *strnum)
{
	const int	neg = 1 - (2 * (*strnum == '-'));
	int			num;

	if (*strnum == '-' || *strnum == '+')
		++strnum;
	num = 0;
	while (ft_isdigit(*strnum))
	{
		num = num * 10 + (*strnum - '0') * neg;
		++strnum;
		if ((neg == -1 && num > 0) || (neg == 1 && num < 0))
			return (-EINVAL);
	}
	return (0);
}

static int	validate_int_format(char *strnum)
{
	if (*strnum == '-' || *strnum == '+')
		++strnum;
	if (!ft_isdigit(*strnum))
		return (-EINVAL);
	while (ft_isdigit(*strnum))
		++strnum;
	if (*strnum != '\0')
		return (-EINVAL);
	return (0);
}

static void	ss_clean(char **substrs_o, char **substrs)
{
	while (*substrs)
	{
		free(*substrs);
		++substrs;
	}
	free(substrs_o);
}

static int	circ_stack_add_strnums(t_circ_stack *cs, char *strnums)
{
	int				status;
	int				num_count;
	char **const	nums_o = ft_split(strnums, ' ');
	char			**nums;

	if (!nums_o)
		return (-ENOMEM);
	nums = nums_o;
	num_count = 0;
	while (*nums)
	{
		status = validate_int_format(*nums);
		if (status)
			return (ss_clean(nums_o, nums), status);
		status = validate_int_overflow(*nums);
		if (status)
			return (ss_clean(nums_o, nums), status);
		circ_stack_push_bottom(cs, ft_atoi(*nums));
		++num_count;
		free(*nums);
		++nums;
	}
	ss_clean(nums_o, nums);
	return (num_count);
}

int	circ_stack_add_strsnums(t_circ_stack *cs, char **strsnums, size_t nstr)
{
	int	n;
	int	num_count;

	num_count = 0;
	while (nstr)
	{
		n = circ_stack_add_strnums(cs, *strsnums++);
		if (n < 0)
			return (n);
		num_count += n;
		--nstr;
	}
	return (num_count);
}
