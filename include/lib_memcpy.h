/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_memcpy.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:15:57 by                   #+#    #+#             */
/*   Updated: 2023/05/02 10:16:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MEMCPY_H
# define LIB_MEMCPY_H

# include <stddef.h>

void *_Nonnull	lib_memcpy(void *_Nonnull dst, void *_Nonnull src, size_t len);

#endif
