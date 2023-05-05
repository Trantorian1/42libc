/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_memcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:07:24 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/02 10:15:08 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_memcpy.h"

#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "g_barrier.h"

extern char	g_barrier[1024];

void *_Nonnull	lib_memcpy(void *_Nonnull dst, void *_Nonnull src, size_t len)
{
	if (dst == NULL || src == NULL)
	{
		errno = EINVAL;
		return (g_barrier);
	}
	return (memcpy(dst, src, len));
}
