/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:36:11 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/25 18:39:46 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_sign.h"

#include <stdlib.h>
#include <stddef.h>
#include <errno.h>

#include "is_digit.h"

char	*parse_sign(char *_Nonnull str, int8_t *_Nonnull sign)
{
	if (str == NULL || sign == NULL)
	{
		errno = EINVAL;
		return (str);
	}
	if (*str == '-')
	{
		str++;
		*sign = -1;
	}
	else if (*str == '+')
	{
		str++;
		*sign = 1;
	}
	else if (is_digit(*str))
		*sign = 1;
	else
		sign = 0;
	return (str);
}
