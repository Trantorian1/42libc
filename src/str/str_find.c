/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:10:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/08 18:34:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_find.h"

#include <stdlib.h>
#include <errno.h>

/**
 * @brief Searches for a set of tokens in a source string.
 *
 * @param str_src (char *_Nonnull): string to search.
 * @param tokens (char *_Nonnull): characters to find in source string.
 *
 * @return (char *_Nonnull): first matching token in source string.
 */
char *_Nonnull	str_find(char *_Nonnull str_src, char *_Nonnull tokens)
{
	char	*cursor;

	if (str_src == NULL || tokens == NULL)
	{
		errno = EINVAL;
		return (str_src);
	}
	while (*str_src != '\0')
	{
		cursor = tokens;
		while (*cursor != '\0')
		{
			if (*str_src == *cursor)
				return (str_src);
			cursor++;
		}
		str_src++;
	}
	return (str_src);
}
