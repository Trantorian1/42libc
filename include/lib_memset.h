/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_memset.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:28:14 by                   #+#    #+#             */
/*   Updated: 2023/05/06 15:29:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MEMSET_H
# define LIB_MEMSET_H

# include <stddef.h>
# include <stdint.h>

void *_Nonnull	lib_memset(void *_Nonnull dst, uint8_t bit, size_t size);

#endif
