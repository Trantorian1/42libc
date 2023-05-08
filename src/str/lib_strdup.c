/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:43:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/08 14:45:45 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_strdup.h"

#include <stdlib.h>
#include <errno.h>
#include <string.h>

char *_Nonnull	lib_strdup(char *_Nonnull str)
{
	if (str == NULL)
	{
		errno = EINVAL;
		return (str);
	}
	return (strdup(str));
}
