/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:35:28 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/26 14:55:29 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>

#include "is_digit.h"

Test(is_digit, is_digit_invalid)
{
	cr_assert_not(is_digit('\0'));
	cr_assert_not(is_digit('0' - 1));
	cr_assert_not(is_digit('9' + 1));
	cr_assert_not(is_digit('~'));
}

Test(is_digit, is_digit_valid)
{
	cr_assert(is_digit('0'));
	cr_assert(is_digit('1'));
	cr_assert(is_digit('2'));
	cr_assert(is_digit('3'));
	cr_assert(is_digit('4'));
	cr_assert(is_digit('5'));
	cr_assert(is_digit('6'));
	cr_assert(is_digit('7'));
	cr_assert(is_digit('8'));
	cr_assert(is_digit('9'));
}
