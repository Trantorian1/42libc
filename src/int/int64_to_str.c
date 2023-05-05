/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int64_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:52:13 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/02 10:17:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int64_to_str.h"

#include "stralloc.h"
#include "lib_memcpy.h"

#define INT64_MIN_STR "-9223372036854775808"
#define INT64_LEN 20

char *_Nonnull	int64_to_str(int64_t n)
{
	int8_t	index;
	int64_t	n_cpy;
	char	*str_dst;
	char	buffer[INT64_LEN];

	index = INT64_LEN;
	n_cpy = n;
	if (n < 0)
	{
		if (n == INT64_MIN)
			return (lib_memcpy(stralloc(INT64_LEN), INT64_MIN_STR, INT64_LEN));
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
	str_dst = stralloc((size_t)(INT64_LEN - index));
	return (lib_memcpy(str_dst, &buffer[index], (size_t)(INT64_LEN - index)));
}
