/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlensize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:45:57 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/29 14:50:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlensize.h"

#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

size_t	strlensize(char *_Nonnull str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
	{
		errno = EINVAL;
		return (len);
	}
	while (str[len] != '\0' && len < SIZE_MAX)
		len++;
	if (str[len] != '\0')
	{
		errno = ERANGE;
		return (0);
	}
	return (len);
}
