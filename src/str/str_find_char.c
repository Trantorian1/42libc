/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_find_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:42:39 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/08 19:22:28 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_find_char.h"

#include <stdlib.h>
#include <errno.h>

char *_Nonnull	str_find_char(char *_Nonnull str_src, char c)
{
	if (str_src == NULL)
	{
		errno = EINVAL;
		return (str_src);
	}
	while (*str_src != '\0' && *str_src != c)
		str_src++;
	return (str_src);
}
