/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:10:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/08 18:15:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_find.h"

#include <stdlib.h>
#include <errno.h>

char *_Nonnull	str_find(char *_Nonnull str_src, char *_Nonnull to_find)
{
	char	*cursor;

	if (str_src == NULL || to_find == NULL)
	{
		errno = EINVAL;
		return (str_src);
	}
	while (*str_src != '\0')
	{
		cursor = to_find;
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
