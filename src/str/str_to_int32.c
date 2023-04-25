/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:07:30 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/25 18:53:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_to_int32.h"

#include <stdlib.h>
#include <errno.h>
#include <stddef.h>
#include <stdbool.h>

#include "parse_whitespace.h"
#include "parse_sign.h"
#include "parse_zero.h"

#define INT32_MAX_STR 2147483647
#define INT32_MIN_STR 2147483648

static bool	is_int32(char *_Nonnull str)
{

}

// TODO: finish this
int32_t	str_to_int32(char *_Nonnull str, char *endptr)
{
	int8_t	sign;

	if (str == NULL)
	{
		errno = EINVAL;
		return (0);
	}
	str = parse_whitespace(str);
	str = parse_sign(str, &sign);
	str = parse_zero(str);
	if (is_int32(str) == false)
	{
		errno = ERANGE;
		return (0);
	}
	return (str_conv32(str));
}
