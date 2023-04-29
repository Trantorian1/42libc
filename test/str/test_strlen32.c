/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen32.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:28:33 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/29 10:44:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <stdlib.h>

#include "strlen32.h"

#define MSG_FORMAT "parsing \"%s\""
#define MSG_FORMAT_INV_LEN MSG_FORMAT ", expected %d, got %d"
#define MSG_FORMAT_RES MSG_FORMAT ": length is %d"

typedef struct s_len_params
{
	char	*str_src;
	int32_t	expected_len;
}	t_s_len_params;

static t_s_len_params	len_params[] = {
	{.str_src = "abc"                        , .expected_len = 3},
	{.str_src = "abcdefghijklmnopqrstuvwxyz" , .expected_len = 26},
	{.str_src = ""                           , .expected_len = 0},
	{.str_src = NULL                         , .expected_len = 0}
};

ParameterizedTestParameters(strlen32_suite, strlen32_test)
{
	size_t	nb_params = sizeof(len_params) / sizeof(*len_params);
	return (cr_make_param_array(t_s_len_params, len_params, nb_params));
}

ParameterizedTest(t_s_len_params *params, strlen32_suite, strlen32_test)
{
	int32_t	len;

	len = strlen32(params->str_src);
	cr_log_info(MSG_FORMAT_RES, params->str_src, len);
	cr_assert_eq(
		len, params->expected_len,
		MSG_FORMAT_INV_LEN,
		params->str_src, params->expected_len, len);
}
