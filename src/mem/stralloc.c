/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stralloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:07:05 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/29 16:09:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stralloc.h"

#include "lib_malloc.h"

char *_Nonnull	stralloc(size_t n)
{
	char	*str;

	str = lib_malloc(sizeof(*str) * (n + 1));
	str[n] = '\0';
	return (str);
}
