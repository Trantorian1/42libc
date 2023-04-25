/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen32.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:50:07 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/25 18:53:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlen32.h"

#include <stdlib.h>
#include <errno.h>

int32_t	strlen32(char *_Nonnull str)
{
	int32_t	len;

	if (str == NULL)
	{
		errno = EINVAL;
		return (0);
	}
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
