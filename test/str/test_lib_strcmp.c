/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lib_strcmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:02:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/26 19:08:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <stdlib.h>

#include "lib_strcmp.h"

#define MSG_FORMAT(str_a, str_b) "comparing \"" #str_a "\" and \"" #str_b "\""
#define MSG_FORMAT_INF(str_a, str_b) MSG_FORMAT(str_a, str_b) ", expected < 0, got %d"
#define MSG_FORMAT_SUP(str_a, str_b) MSG_FORMAT(str_a, str_b) ", expected > 0, got %d"
#define MSG_FORMAT_EQL(str_a, str_b) MSG_FORMAT(str_a, str_b) ", expected 0, got %d"
#define MSG_FORMAT_RES(str_a, str_b) MSG_FORMAT(str_a, str_b) ": %d"

Test(lib_strcmp, lib_strcmp_inferior)
{
	static void	*null = NULL;
	int32_t		cmp;

	cmp = lib_strcmp("Tess", "Test");
	cr_log_info(MSG_FORMAT_RES(Tess, Test), cmp);
	cr_assert_lt(cmp, 0, MSG_FORMAT_INF(Tess, Test), cmp);
	
	cmp = lib_strcmp("Te", "Test");
	cr_log_info(MSG_FORMAT_RES(Te, Test), cmp);
	cr_assert_lt(cmp, 0, MSG_FORMAT_INF(Te, Test), cmp);

	cmp = lib_strcmp("", "Test");
	cr_log_info(MSG_FORMAT_RES( , Test), cmp);
	cr_assert_lt(cmp, 0, MSG_FORMAT_INF( , Test), cmp);

	cmp = lib_strcmp(null, "Test");
	cr_log_info(MSG_FORMAT_RES(NULL, Test), cmp);
	cr_assert_lt(cmp, 0, MSG_FORMAT_INF(NULL, Test), cmp);

	cmp = lib_strcmp("acde", "bbde");
	cr_log_info(MSG_FORMAT_RES(acde, bbde), cmp);
	cr_assert_lt(cmp, 0, MSG_FORMAT_INF(acde, bbde), cmp);
}

Test(lib_strcmp, lib_strcmp_superior)
{
	static void	*null = NULL;
	int32_t		cmp;

	cmp = lib_strcmp("Test", "Tess");
	cr_log_info(MSG_FORMAT_RES(Test, Tess), cmp);
	cr_assert_gt(cmp, 0, MSG_FORMAT_SUP(Test, Tess), cmp);

	cmp = lib_strcmp("Test", "Te");
	cr_log_info(MSG_FORMAT_RES(Test, Te), cmp);
	cr_assert_gt(cmp, 0, MSG_FORMAT_SUP(Test, Te), cmp);

	cmp = lib_strcmp("Test", "");
	cr_log_info(MSG_FORMAT_RES(Test, ), cmp);
	cr_assert_gt(cmp, 0, MSG_FORMAT_SUP(Test, ), cmp);

	cmp = lib_strcmp("Test", null);
	cr_log_info(MSG_FORMAT_RES(Test, NULL), cmp);
	cr_assert_gt(cmp, 0, MSG_FORMAT_SUP(Test, NULL), cmp);

	cmp = lib_strcmp("bbde", "acde");
	cr_log_info(MSG_FORMAT_RES(bbde, acde), cmp);
	cr_assert_gt(cmp, 0, MSG_FORMAT_SUP(bbde, acde), cmp);
}

Test(lib_strcmp, lib_strcmp_equal)
{
	static void	*null = NULL;
	int32_t		cmp;

	cmp = lib_strcmp("Test", "Test");
	cr_log_info(MSG_FORMAT_RES(Test, Test), cmp);
	cr_assert_eq(cmp, 0, MSG_FORMAT_EQL(Test, Test), cmp);

	cmp = lib_strcmp("", "");
	cr_log_info(MSG_FORMAT_RES(, ), cmp);
	cr_assert_eq(cmp, 0, MSG_FORMAT_EQL( , ), cmp);

	cmp = lib_strcmp(null, null);
	cr_log_info(MSG_FORMAT_RES(NULL, NULL), cmp);
	cr_assert_eq(cmp, 0, MSG_FORMAT_EQL(NULL, NULL), cmp);
}
