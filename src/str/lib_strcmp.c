/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:50:17 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/26 18:33:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_strcmp.h"

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int32_t	lib_strcmp(char *_Nonnull str_a, char *_Nonnull str_b)
{
	int32_t	diff;

	if (str_a == NULL || str_b == NULL)
	{
		errno = EINVAL;
		if (str_b != NULL)
			return (-*str_b);
		if (str_a != NULL)
			return (*str_a);
		return (0);
	}
	diff = 0;
	while (*str_a && *str_b)
	{
		diff += *str_a - *str_b;
		if (*str_a != *str_b)
			return (diff);
		str_a++;
		str_b++;
	}
	diff += *str_a - *str_b;
	return (diff);
}
