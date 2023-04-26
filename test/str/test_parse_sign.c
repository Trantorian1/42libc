/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:03:20 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/26 19:41:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <stdint.h>

#include "parse_sign.h"

#define MSG_FORMAT(str_a) "parsing \"" #str_a "\"" 
#define MSG_FORMAT_INV_STR(str_a) MSG_FORMAT(str_a) ", expected %s, got %s"
#define MSG_FORMAT_INV_SIGN(str_a) MSG_FORMAT(str_a) ", expected %d, got %d"
#define MSG_FORMAT_RES(str_a) MSG_FORMAT(str_a) ": sign is %d"

Test(parse_sign, parse_sign_invalid)
{
	char	*str_src;
	char	*str_dst;
	int8_t	sign;

	// test for str == NULL, sign should be 0 and return should be NULL
	str_src = NULL;
	str_dst = parse_sign(str_src, &sign);
	cr_log_info(MSG_FORMAT_RES(NULL), sign);
	cr_assert_eq(
		str_dst, str_src,
		MSG_FORMAT_INV_STR(NULL),
		str_src, str_dst);
	cr_assert_eq(
		sign, 0,
		MSG_FORMAT_INV_SIGN(NULL),
		0, sign);

	// test for str == "", sign should be 0 and return should be str
	str_src = "";
	str_dst = parse_sign(str_src, &sign);
	cr_log_info(MSG_FORMAT_RES(""), sign);
	cr_assert_str_eq(
		str_dst, str_src,
		MSG_FORMAT_INV_STR(""),
		str_src, str_dst);
	cr_assert_eq(
		sign, 0,
		MSG_FORMAT_INV_SIGN(""),
		0, sign);

	// test for str == "\D+", sign should be 0 and return should be str
	str_src = "abcd";
	str_dst = parse_sign(str_src, &sign);
	cr_log_info(MSG_FORMAT_RES(abcd), sign);
	cr_assert_str_eq(
		str_dst, str_src,
		MSG_FORMAT_INV_STR(abcd),
		str_src, str_dst);
	cr_assert_eq(
		sign, 0,
		MSG_FORMAT_INV_SIGN(abcd),
		0, sign);
}

Test(parse_sign, parse_sign_valid)
{
	char	*str_src;
	char	*str_dst;
	int8_t	sign;

	// test for str == "-\d*", sign should be -1 and return should be (str + 1) 
	str_src = "-123";
	str_dst = parse_sign(str_src, &sign);
	cr_log_info(MSG_FORMAT_RES(-123), sign);
	cr_assert_str_eq(
		str_dst, str_src + 1, 
		MSG_FORMAT_INV_STR(-123),
		str_src + 1, str_dst);
	cr_assert_eq(
		sign, -1,
		MSG_FORMAT_INV_SIGN(-123),
		-1, sign);

	// test for str == "+\d*", sign should be +1 and return should be (str + 1)
	str_src = "+123";
	str_dst = parse_sign(str_src, &sign);
	cr_log_info(MSG_FORMAT_RES(+123), sign);
	cr_assert_str_eq(
		str_dst, str_src + 1,
		MSG_FORMAT_INV_STR(+123),
		str_src + 1, str_dst);
	cr_assert_eq(
		sign, +1,
		MSG_FORMAT_INV_SIGN(+123),
		+1, sign);

	// test for str == "\d+", sign should be +1 and return should be str
	str_src = "123";
	str_dst = parse_sign(str_src, &sign);
	cr_log_info(MSG_FORMAT_RES(123), sign);
	cr_assert_str_eq(
		str_dst, str_src,
		MSG_FORMAT_INV_STR(123),
		str_src, str_dst);
	cr_assert_eq(
		sign, +1,
		MSG_FORMAT_INV_SIGN(123),
		+1, sign);
}
