/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:32:26 by emcnab            #+#    #+#             */
/*   Updated: 2023/05/09 11:33:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_exit.h"

#include <stdlib.h>
#include <errno.h>

#include "lib_malloc.h"

void _Noreturn	lib_exit(void)
{
	lib_freeall();
	exit(errno);
}
