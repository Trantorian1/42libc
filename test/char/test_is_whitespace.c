/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_whitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:54:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/26 15:01:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>

#include "is_whitespace.h"

Test(is_whitespace, is_whitespace_invalid)
{
	char	c;

	c = '\0' ;
	while (++c < '\t')
		cr_assert_not(is_whitespace(c));
	c = '\r';
	while (++c < ' ')
		cr_assert_not(is_whitespace(c));
	while (++c < '~')
		cr_assert_not(is_whitespace(c));
	cr_assert_not(is_whitespace(c));
}

Test(is_whitespace, is_whitespace_valid)
{
	static char	whitespace[] = {'\t', '\n', '\v', '\f', '\r'};
	int8_t		index;
	int8_t		target;

	index = (-1);
	target = sizeof(whitespace) / sizeof(*whitespace);
	while (++index < target)
		cr_assert(is_whitespace(whitespace[index]));
}
