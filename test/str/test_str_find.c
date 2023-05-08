/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:15:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/08 18:31:24 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "str_find.h"

#define MSG_FORMAT "searching \"%s\""
#define MSG_FORMAT_INV_STR MSG_FORMAT ", expected \"%s\", got \"%s\""
#define MSG_FORMAT_RES MSG_FORMAT ": found a match at \"%s\""

typedef struct s_str_find_params
{
	char	*str_src;
	char	*to_find;
	char	*expected_str;
}	t_s_str_find_params;

static t_s_str_find_params	str_find_params[] = {
	{.str_src = ""    , .to_find = ""    , .expected_str = ""},
	{.str_src = "abcd", .to_find = "a"   , .expected_str = "abcd"},
	{.str_src = "abcd", .to_find = "b"   , .expected_str = "bcd"},
	{.str_src = "abcd", .to_find = "c"   , .expected_str = "cd"},
	{.str_src = "abcd", .to_find = "d"   , .expected_str = "d"},
	{.str_src = "abcd", .to_find = "z"   , .expected_str = ""},
	{.str_src = "abcd", .to_find = NULL  , .expected_str = "abcd"},
	{.str_src = NULL  , .to_find = "abcd", .expected_str = NULL},
	{.str_src = NULL  , .to_find = NULL  , .expected_str = NULL}
};

ParameterizedTestParameters(str_find_suite, str_find_test)
{
	size_t	nb_params = sizeof(str_find_params) / sizeof(*str_find_params);
	return (cr_make_param_array(t_s_str_find_params, str_find_params, nb_params));
}

ParameterizedTest(t_s_str_find_params *params, str_find_suite, str_find_test)
{
	char	*str_dst;

	str_dst = str_find(params->str_src, params->to_find);
	cr_log_info(MSG_FORMAT_RES, params->str_src, str_dst);

	if (params->expected_str == NULL)
		cr_assert_eq(
			str_dst, params->expected_str,
			MSG_FORMAT_INV_STR,
			params->str_src, params->expected_str, str_dst);
	else
		cr_assert_str_eq(
			str_dst, params->expected_str,
			MSG_FORMAT_INV_STR,
			params->str_src, params->expected_str, str_dst);
}
