/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:50:17 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/26 09:55:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_strcmp.h"

#include <stdlib.h>
#include <errno.h>

int32_t	lib_strcmp(char *_Nonnull str_a, char *_Nonnull str_b)
{
	int32_t	diff;

	if (str_a == NULL || str_b == NULL)
	{
		errno = EINVAL;
		return (0);
	}
	diff = 0;
	while (*str_a && *str_b)
	{
		diff += *str_a - *str_b;
		str_a++;
		str_b++;
	}
	while (*str_a)
		diff += *str_a++;
	while (*str_b)
		diff += *str_b++;
	return (diff);
}
