/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int32_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:09:57 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/29 17:24:05 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int32_to_str.h"

#include "stralloc.h"
#include "int32_len.h"
#include <string.h>

#define INT32_MIN_STR "-2147483648"
#define INT32_LEN 12

char *_Nonnull	int32_to_str(int32_t n)
{
	int8_t	index;
	int32_t	n_cpy;
	char	*str_dst;
	char	buffer[INT32_LEN];

	index = INT32_LEN;
	n_cpy = n;
	if (n < 0)
	{
		if (n == INT32_MIN)
			return (memcpy(stralloc(INT32_LEN), INT32_MIN_STR, INT32_LEN));
		n_cpy = -n;
	}
	while (n_cpy > 9)
	{
		buffer[--index] = n_cpy % 10 + '0';
		n_cpy /= 10;
	}
	buffer[--index] = n_cpy % 10 + '0';
	if (n < 0)
		buffer[--index] = '-';
	str_dst = stralloc((size_t)(INT32_LEN - index));
	return (memcpy(str_dst, &buffer[index], (size_t)(INT32_LEN - index)));
}
