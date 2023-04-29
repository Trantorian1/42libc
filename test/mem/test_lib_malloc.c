/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lib_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 14:18:12 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/29 15:04:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "lib_malloc.h"
#include "strlensize.h"

// TEST: basic memory allocation and freeing
Test(lib_malloc_suite, lib_malloc_test_malloc_single)
{
	int8_t			*int_array;
	size_t			index;
	static size_t	size = 8;

	int_array = lib_malloc(sizeof(*int_array) * size);

	index = (size_t)(-1);
	while (++index < size)
	{
		int_array[index] = (int8_t)index;
	}

	index = (size_t)(-1);
	while (++index < size)
	{
		cr_assert_eq(
			int_array[index], (int8_t)index,
			"scanning int8 array, expected %d, got %d",
			(int8_t)index, int_array[index]);
	}

	lib_free(int_array);
	cr_assert_not(is_leaking());
}

// TEST: multiple mallocs and frees
Test(lib_malloc_suite, lib_malloc_test_malloc_multiple)
{
	char			**str_array;
	size_t			index;
	static size_t	size;
	
	str_array = lib_malloc(sizeof(*str_array) * size);
	
	index = (size_t)(-1);
	while (++index < size)
	{
		str_array[index] = lib_malloc(sizeof(**str_array) * 2);
		str_array[index][0] = 'a' + (char)index;
		str_array[index][1] = '\0';
	}

	index = (size_t)(-1);
	while (++index < size)
	{
		cr_assert_eq(
			str_array[index][0], 'a' + (char)index,
			"scanning 2d str array, expected %c, got %c",
			'a' + (char)index, str_array[index][0]);
	}

	index = (size_t)(-1);
	while (++index < size)
	{
		lib_free(str_array[index]);
	}
	lib_free(str_array);
	cr_assert_not(is_leaking());
}

// TEST: lib_freeall
Test(lib_malloc_suite, lib_malloc_test_freeall)
{
	char			**str_array;
	size_t			index;
	static size_t	size;
	
	str_array = lib_malloc(sizeof(*str_array) * size);
	
	index = (size_t)(-1);
	while (++index < size)
		str_array[index] = lib_malloc(sizeof(**str_array) * 2);

	lib_freeall();
	cr_assert_not(is_leaking());
}

// TEST: lib_realloc
Test(lib_malloc_suite, lib_malloc_test_realloc)
{
	char			*str;
	static char		*str_a = "Hello Malloc!";
	static char		*str_b = "Hello String, how are you?";

	str = lib_malloc(sizeof(*str) * (strlensize(str_a) + 1));
	memcpy(str, str_a, strlensize(str_a) + 1);
	cr_assert_str_eq(
		str, str_a,
		"Copying string %s, got %s instead",
		str_a, str);
	cr_log_info("Copied string %s via mallocation", str_a);

	str = lib_realloc(str, sizeof(*str) * (strlensize(str_b) + 1));
	memcpy(str, str_b, strlensize(str_b) + 1);
	cr_assert_str_eq(
		str, str_b,
		"Copying string %s, got %s instead",
		str_b, str);
	cr_log_info("Copied string %s via reallocation", str_b);

	lib_free(str);
	cr_assert_not(is_leaking());
}

