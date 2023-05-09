/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_memdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:28:17 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/09 11:39:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_memdup.h"

#include <stdlib.h>
#include <errno.h>

#include "lib_malloc.h"
#include "lib_memcpy.h"

void *_Nonnull	lib_memdup(void *_Nonnull src, size_t len)
{
	if (src == NULL)
	{
		errno = EINVAL;
		return (src);
	}
	return (lib_memcpy(lib_malloc(len), src, len));
}
