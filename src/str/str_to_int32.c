/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:07:30 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/26 14:48:50 by emcnab           ###   ########.fr       */
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
#include "is_digit.h"
#include "strlen32.h"
#include "lib_strcmp.h"

#define INT32_MAX_STR "2147483647"
#define INT32_MIN_STR "2147483648"

static bool	is_int32(char *_Nonnull str, int8_t sign)
{
	if (sign == -1)
		return (lib_strcmp(INT32_MIN_STR, str) >= 0);
	if (sign == +1)
		return (lib_strcmp(INT32_MAX_STR, str) >= 0);
	return (false);
}

static int32_t	str_conv32_negative(
	char *_Nonnull str,
	char *_Nonnull*_Nullable endptr)
{
	int32_t	result;
	int32_t	char_val;

	result = 0;
	while (is_digit(*str))
	{
		char_val = *str - '0';
		result *= 10;
		if (char_val - 1 - result > INT32_MAX)
		{
			*endptr = str;
			errno = ERANGE;
			return (result);
		}
		result = result - char_val;
	}
	return (result);
}

static int32_t	str_conv32_positive(
	char *_Nonnull str,
	char *_Nonnull*_Nullable endptr)
{
	int32_t	result;
	int32_t	char_val;

	result = 0;
	while (is_digit(*str))
	{
		char_val = *str - '0';
		result *= 10;
		if (char_val > INT32_MAX - result)
		{
			*endptr = str;
			errno = ERANGE;
			return (result);
		}
		result = result + char_val;
	}
	return (result);
}

static int32_t	str_conv32(
	char *_Nonnull str,
	char *_Nonnull*_Nullable endptr,
	int8_t sign)
{
	if (sign == -1)
		return (str_conv32_negative(str, endptr));
	if (sign == +1)
		return (str_conv32_positive(str, endptr));
	return (0);
}

int32_t	str_to_int32(char *_Nonnull str, char *_Nonnull*_Nullable endptr)
{
	int8_t	sign;

	if (str == NULL || endptr == NULL)
	{
		errno = EINVAL;
		return (0);
	}
	str = parse_whitespace(str);
	str = parse_sign(str, &sign);
	str = parse_zero(str);
	if (is_int32(str, sign) == false)
	{
		errno = ERANGE;
		return (0);
	}
	return (str_conv32(str, endptr, sign));
}
