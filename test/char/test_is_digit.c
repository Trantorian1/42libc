/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_digit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:35:28 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/26 13:50:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>

#include "is_digit.h"

Test(is_digit, is_digit_invalid) {
	cr_assert_not(is_digit('\0'));
}

Test(is_digit, is_digit_valid) {
	cr_assert(is_digit('0'));
}
