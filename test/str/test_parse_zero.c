/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:50:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/26 21:05:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <stdlib.h>

#include "parse_zero.h"

#define MSG_FORMAT "parsing \"%s\""
#define MSG_FORMAT_STR_INV MSG_FORMAT ", expected \"%s\", got \"%s\""
#define MSG_FORMAT_RES MSG_FORMAT ": result is \"%s\""

typedef struct s_zero_params
{
	char	*str_src;
	char	*expected;
}	t_s_zero_params;

// TODO: add errno testing
t_s_zero_params	zero_params[] = {
	{.str_src = "0"    , .expected = ""  },
	{.str_src = "000"  , .expected = ""  },
	{.str_src = "01"   , .expected = "1" },
	{.str_src = "0001" , .expected = "1" },
	{.str_src = ""     , .expected = ""  },
	{.str_src = NULL   , .expected = NULL}
};

ParameterizedTestParameters(parse_zero_suite, parse_zero_test)
{
	size_t	nb_params = sizeof(zero_params) / sizeof(*zero_params);
	return (cr_make_param_array(t_s_zero_params, zero_params, nb_params));
}

ParameterizedTest(t_s_zero_params *params, parse_zero_suite, parse_zero_test)
{
	char	*str_dst;

	str_dst = parse_zero(params->str_src);
	cr_log_info(MSG_FORMAT_RES, params->str_src, str_dst);
	if (params->str_src == NULL)
		cr_assert_eq(
			str_dst, params->expected,
			MSG_FORMAT_STR_INV,
			params->str_src, params->expected, str_dst);
	else
		cr_assert_str_eq(
			str_dst, params->expected,
			MSG_FORMAT_STR_INV,
			params->str_src, params->expected, str_dst);
}
