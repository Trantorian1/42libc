/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:26:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/26 12:03:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_whitespace.h"

#include <stdlib.h>
#include <errno.h>

#include "is_whitespace.h"

char *_Nonnull	parse_whitespace(char *_Nonnull str)
{
	if (str == NULL)
	{
		errno = EINVAL;
		return (str);
	}
	while (is_whitespace(*str))
		str++;
	return (str);
}
