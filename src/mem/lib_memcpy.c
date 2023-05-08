/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_memcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:07:24 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/08 11:47:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_memcpy.h"

#include <stdlib.h>
#include <errno.h>
#include <string.h>

void *_Nonnull	lib_memcpy(void *_Nonnull dst, void *_Nonnull src, size_t len)
{
	if (dst == NULL || src == NULL)
	{
		errno = EINVAL;
		return (dst);
	}
	return (memcpy(dst, src, len));
}
