/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_to_int32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:41:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/29 13:00:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/parameterized.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "str_to_int32.h"

#define MSG_FORMAT "parsing \"%s\""
#define MSG_FORMAT_INV_INT MSG_FORMAT ", expected %d, got %d"
#define MSG_FORMAT_INV_END MSG_FORMAT ", expected \"%s\", got \"%s\""
#define MSG_FORMAT_RES MSG_FORMAT ": result is %d with endptr \"%s\""
#define WHITESPACED(n) "\t\n\v\f\r " #n

typedef struct s_to_int_param
{
	char	*str_src;
	char	*expect_endptr;
	int32_t	expect_int;
}	t_s_to_int_param;

static t_s_to_int_param	to_int_params[] = {
	{.str_src = WHITESPACED(123)   , .expect_endptr = ""           , .expect_int = 123},
	{.str_src = WHITESPACED(123a)  , .expect_endptr = "a"          , .expect_int = 123},
	{.str_src = WHITESPACED(1 23a) , .expect_endptr = " 23a"       , .expect_int = 1},
	{.str_src = WHITESPACED(+)     , .expect_endptr = ""           , .expect_int = 0},
	{.str_src = WHITESPACED(-)     , .expect_endptr = ""           , .expect_int = 0},
	{.str_src = WHITESPACED()      , .expect_endptr = ""           , .expect_int = 0},
	{.str_src = WHITESPACED(a)     , .expect_endptr = "a"          , .expect_int = 0},
	{.str_src = WHITESPACED(+a)    , .expect_endptr = "a"          , .expect_int = 0},
	{.str_src = WHITESPACED(-a)    , .expect_endptr = "a"          , .expect_int = 0},
	{.str_src = "123"              , .expect_endptr = ""           , .expect_int = 123},
	{.str_src = "123a"             , .expect_endptr = "a"          , .expect_int = 123},
	{.str_src = "1 23a"            , .expect_endptr = " 23a"       , .expect_int = 1},
	{.str_src = "+"                , .expect_endptr = ""           , .expect_int = 0},
	{.str_src = "-"                , .expect_endptr = ""           , .expect_int = 0},
	{.str_src = ""                 , .expect_endptr = ""           , .expect_int = 0},
	{.str_src = "a"                , .expect_endptr = "a"          , .expect_int = 0},
	{.str_src = "+a"               , .expect_endptr = "a"          , .expect_int = 0},
	{.str_src = "-a"               , .expect_endptr = "a"          , .expect_int = 0},
	{.str_src = "2147483647"       , .expect_endptr = ""           , .expect_int = 2147483647},
	{.str_src = "-2147483648"      , .expect_endptr = ""           , .expect_int = -2147483648},
	{.str_src = "2147483648"       , .expect_endptr = "2147483648" , .expect_int = 0},
	{.str_src = "-2147483649"      , .expect_endptr = "2147483649" , .expect_int = 0},
	{.str_src = "100"              , .expect_endptr = ""           , .expect_int = 100},
	{.str_src = "-100"             , .expect_endptr = ""           , .expect_int = -100},
	{.str_src = "0"                , .expect_endptr = ""           , .expect_int = 0},
	{.str_src = "12"               , .expect_endptr = ""           , .expect_int = 12},
	{.str_src = "-12"              , .expect_endptr = ""           , .expect_int = -12},
	{.str_src = NULL               , .expect_endptr = NULL         , .expect_int = 0}
};

ParameterizedTestParameters(to_int_suite, to_int_test)
{
	size_t	nb_params = sizeof(to_int_params) / sizeof(*to_int_params);
	return (cr_make_param_array(t_s_to_int_param, to_int_params, nb_params));
}

ParameterizedTest(t_s_to_int_param *params, to_int_suite, to_int_test)
{
	char	*endptr;
	int32_t	result;

	result = str_to_int32(params->str_src, &endptr);
	cr_log_info(MSG_FORMAT_RES, params->str_src, result, endptr);
	cr_assert_eq(
		result, params->expect_int,
		MSG_FORMAT_INV_INT,
		params->str_src, params->expect_int, result);
	if (params->expect_endptr == NULL)
		cr_assert_eq(
			endptr, params->expect_endptr,
			MSG_FORMAT_INV_END,
			params->str_src, params->expect_endptr, endptr);
	else
		cr_assert_str_eq(
			endptr, params->expect_endptr,
			MSG_FORMAT_INV_END,
			params->str_src, params->expect_endptr, endptr);
}

// Test(to_int_suite, to_int_random)
// {
// 	int8_t	index;
// 	int32_t	n;
// 	char	*str_src;
//
// 	srand((uint32_t)time(NULL));
// 	
// 	index = -1;
// 	while (++index < 100)
// 	{
// 		n = rand() % INT32_MAX - INT32_MAX / 2;
// 		str = itoa(n);
// 	}
// }
