/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:09:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/08 15:22:00 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "lib_strdup.h"
#include "lib_malloc.h"

#define MSG_FORMAT "duplicating \"%s\""
#define MSG_FORMAT_INV_STR MSG_FORMAT ", expected \"%s\", got \"%s\""
#define MSG_FORMAT_RES MSG_FORMAT ":result is \"%s\""

static char	*strdup_params[] = {
	"",
	"test",
	"\0 test",
	NULL
};

ParameterizedTestParameters(lib_strdup_suite, lib_strdup_test)
{
	size_t	nb_params = sizeof(strdup_params) / sizeof(*strdup_params);
	return (cr_make_param_array(char *, strdup_params, nb_params));
}

ParameterizedTest(char *str_src, lib_strdup_suite, lib_strdup_test)
{
	char	*str_dst;

	str_dst = lib_strdup(str_src);
	cr_log_info(MSG_FORMAT_RES, str_src, str_dst);
	if (str_src == NULL)
		cr_assert_eq(
			str_dst, str_src,
			MSG_FORMAT_INV_STR,
			str_src, str_src, str_dst);
	else
		cr_assert_str_eq(
			str_dst, str_src,
			MSG_FORMAT_INV_STR,
			str_src, str_src, str_dst);
	lib_free(str_dst);

	cr_assert_not(is_leaking());
}
