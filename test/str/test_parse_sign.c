/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:03:20 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/29 10:32:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <stdlib.h>

#include "parse_sign.h"

#define MSG_FORMAT "parsing \"%s\""
#define MSG_FORMAT_INV_STR MSG_FORMAT ", expected \"%s\", got \"%s\""
#define MSG_FORMAT_INV_SIGN MSG_FORMAT ", expected \"%d\", got \"%d\""
#define MSG_FORMAT_RES MSG_FORMAT ": sign is %d"

typedef struct s_sign_params
{
	char	*str_src;
	char	*expected_str;
	int8_t	expected_sign;
}	t_s_sign_params;

static t_s_sign_params	sign_params[] = {
	{.str_src = "-123", .expected_str = "123", .expected_sign = -1},
	{.str_src = "+123", .expected_str = "123", .expected_sign = +1},
	{.str_src = "123" , .expected_str = "123", .expected_sign = +1},
	{.str_src = "abc" , .expected_str = "abc", .expected_sign = 0 },
	{.str_src = ""    , .expected_str = ""   , .expected_sign = 0 },
	{.str_src = NULL  , .expected_str = NULL , .expected_sign = 0 },
};

ParameterizedTestParameters(parse_sign_suite, parse_sign_test)
{
	size_t	nb_params = sizeof(sign_params) / sizeof(*sign_params);
	return (cr_make_param_array(t_s_sign_params, sign_params, nb_params));
}

ParameterizedTest(t_s_sign_params *params, parse_sign_suite, parse_sign_test)
{
	char	*str_dst;
	int8_t	sign;

	str_dst = parse_sign(params->str_src, &sign);
	cr_log_info(MSG_FORMAT_RES, params->str_src, sign);
	if (params->str_src == NULL || params->expected_str == NULL)
		cr_assert_eq(
			str_dst, params->expected_str,
			MSG_FORMAT_INV_STR,
			params->str_src, params->expected_str, str_dst);
	else
		cr_assert_str_eq(
			str_dst, params->expected_str,
			MSG_FORMAT_INV_STR,
			params->str_src, params->expected_str, str_dst);
	cr_assert_eq(
		sign, params->expected_sign,
		MSG_FORMAT_INV_SIGN,
		params->str_src, params->expected_sign, sign);
}
