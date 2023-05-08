/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_memset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:27:22 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/06 15:30:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_memset.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>

void *_Nonnull	lib_memset(void *_Nonnull dst, uint8_t bit, size_t size)
{
	if (dst == NULL)
		errno = EINVAL;
	return (memset(dst, bit, size));
}
