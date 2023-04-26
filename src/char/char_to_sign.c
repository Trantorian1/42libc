/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:23:37 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/25 18:25:00 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char_to_sign.h"

int8_t	char_to_sign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (+1);
	return (0);
}