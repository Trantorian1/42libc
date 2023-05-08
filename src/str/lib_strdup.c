/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:43:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/08 15:21:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_strdup.h"

#include <stdlib.h>
#include <errno.h>

#include "strlensize.h"
#include "stralloc.h"
#include "lib_memcpy.h"

char *_Nonnull	lib_strdup(char *_Nonnull str_src)
{
	size_t	len;
	char	*str_dst;

	if (str_src == NULL)
	{
		errno = EINVAL;
		return (str_src);
	}
	len = strlensize(str_src);
	str_dst = stralloc(len);
	lib_memcpy(str_dst, str_src, len * sizeof(*str_src));
	return (str_dst);
}
