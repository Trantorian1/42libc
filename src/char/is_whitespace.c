/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:19:36 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/25 18:21:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_whitespace.h"

bool	is_whitespace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}
