/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bzero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:26:32 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/06 15:32:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bzero.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>

void *_Nonnull	lib_bzero(void *_Nonnull dst, size_t size)
{
	if (dst == NULL)
		errno = EINVAL;
	bzero(dst, size);
	return (dst);
}
