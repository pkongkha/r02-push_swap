/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count_from_strsnums.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:21:29 by pkongkha          #+#    #+#             */
/*   Updated: 2026/03/18 15:24:17 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "word_count.h"

#include <stddef.h>

size_t	word_count_from_strsnums(char **strs, size_t nstr)
{
	size_t	wc;

	wc = 0;
	while (nstr)
	{
		wc += word_count(*strs++);
		--nstr;
	}
	return (wc);
}


