/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int64_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:58:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/02 10:02:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/parameterized.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "int64_to_str.h"
#include "lib_malloc.h"

#define INT64_MAX_STR "9223372036854775807"
#define INT64_MIN_STR "-9223372036854775808"
#define MSG_FORMAT "converting %ld"
#define MSG_FORMAT_INV_STR MSG_FORMAT ", expected \"%s\", got \"%s\""
#define MSG_FORMAT_RES MSG_FORMAT ": result is \"%s\""

typedef struct s_int64_to_str_param
{
	int64_t	int_src;
	char	*expected_str;
}	t_s_int32_to_str_param;

static t_s_int32_to_str_param	int64_to_str_params[] = {
	{.int_src = 0, .expected_str = "0"},
	{.int_src = 12, .expected_str = "12"},
	{.int_src = -12, .expected_str = "-12"},
	{.int_src = 100, .expected_str = "100"},
	{.int_src = -100, .expected_str = "-100"},
	{.int_src = 7, .expected_str = "7"},
	{.int_src = -7, .expected_str = "-7"},
	{.int_src = INT64_MAX, .expected_str = INT64_MAX_STR},
	{.int_src = INT64_MIN, .expected_str = INT64_MIN_STR},
};

ParameterizedTestParameters(int64_to_str_suite, int64_to_str_test)
{
	size_t	nb_param = sizeof(int64_to_str_params) / sizeof(*int64_to_str_params);
	return (
		cr_make_param_array(
			t_s_int32_to_str_param, int64_to_str_params, nb_param));
}

ParameterizedTest(
	t_s_int32_to_str_param *params,
	int64_to_str_suite,
	int64_to_str_test)
{
	char	*str_dst;

	str_dst = int64_to_str(params->int_src);
	cr_log_info(MSG_FORMAT_RES, params->int_src, str_dst);
	cr_assert_str_leq(
		str_dst, params->expected_str,
		MSG_FORMAT_INV_STR,
		params->int_src, params->expected_str, str_dst);
	lib_free(str_dst);
}
