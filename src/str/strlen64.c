/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:42:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/29 14:50:46 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen64.h"

#include <stdlib.h>
#include <errno.h>

int64_t	strlen64(char *_Nonnull str)
{
	int64_t	len;

	len = 0;
	if (str == NULL)
	{
		errno = EINVAL;
		return (len);
	}
	while (str[len] != '\0' && len < INT64_MAX)
		len++;
	if (str[len] != '\0')
	{
		errno = ERANGE;
		return (0);
	}
	return (len);
}
