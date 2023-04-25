/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:40:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/25 18:42:14 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_zero.h"

#include <stdlib.h>
#include <errno.h>

char	*parse_zero(char *_Nonnull str)
{
	if (str == NULL)
	{
		errno = EINVAL;
		return (str);
	}
	while (*str == '0')
		str++;
	return (str);
}
