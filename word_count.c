/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:20:03 by pkongkha          #+#    #+#             */
/*   Updated: 2026/03/18 15:20:09 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	word_count(char *s)
{
	int		in_word;
	size_t	wc;

	in_word = 0;
	wc = 0;
	while (*s)
	{
		if (ft_isspace(*s))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			++wc;
		}
		++s;
	}
	return (wc);
}
