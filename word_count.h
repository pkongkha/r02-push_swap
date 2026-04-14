/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkongkha <pkongkha@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:23:04 by pkongkha          #+#    #+#             */
/*   Updated: 2026/03/18 15:23:24 by pkongkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_COUNT_H
# define WORD_COUNT_H
# include <stddef.h>

size_t	word_count_from_strsnums(char **strs, size_t nstr);
size_t	word_count(char *s);
#endif