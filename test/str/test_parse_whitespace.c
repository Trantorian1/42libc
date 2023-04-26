/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_whitespace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:44:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/26 20:49:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <stdlib.h>

#include "parse_whitespace.h"

// message formats using for error display and verbose logging
#define MSG_FORMAT "parsing \"%s\""
#define MSG_FORMAT_INV_STR MSG_FORMAT ", expected \"%s\", got \"%s\""
#define MSG_FORMAT_RES MSG_FORMAT ": string is now \"%s\""

typedef struct s_whitespace_params
{
	char	*str_src;
	char	*expected;
}	t_s_whitespace_params;

// Test will be run on each of these parameters:
//
// - str_src: source string to be parsed
// - expected: expected result after parsing
t_s_whitespace_params	whitespace_params[] = {
	{.str_src = "\t\t\tabc"     , .expected = "abc"}, 
	{.str_src = "\n\n\ndef"     , .expected = "def"}, 
	{.str_src = "\v\v\vghi"     , .expected = "ghi"}, 
	{.str_src = "\f\f\fjkl"     , .expected = "jkl"}, 
	{.str_src = "\r\r\rmno"     , .expected = "mno"}, 
	{.str_src = "      pqr"     , .expected = "pqr"}, 
	{.str_src = "\t\n\v\f\r stu", .expected = "stu"}, 
	{.str_src = "vwx"           , .expected = "vwx"}, 
	{.str_src = ""              , .expected = ""   },
	{.str_src = NULL            , .expected = NULL },
};

// Generates parameters for criterion
ParameterizedTestParameters(parse_whitespace_suite, parse_whitespace_test)
{
	size_t	nb_params = sizeof(whitespace_params) / sizeof(*whitespace_params);
	return (
		cr_make_param_array(
			t_s_whitespace_params,
			whitespace_params,
			nb_params));
}

// This will run with every parameter in whitespace_params
ParameterizedTest(
	t_s_whitespace_params *params,
	parse_whitespace_suite,
	parse_whitespace_test)
{
	char	*str_dst;

	str_dst = parse_whitespace(params->str_src);
	cr_log_info(MSG_FORMAT_RES, params->str_src, str_dst);
	if (params->str_src == NULL)
		cr_assert_eq(
			str_dst, params->expected,
			MSG_FORMAT_INV_STR,
			params->str_src, params->expected, str_dst);
	else
		cr_assert_str_eq(
			str_dst, params->expected,
			MSG_FORMAT_INV_STR,
			params->str_src, params->expected, str_dst);
}
