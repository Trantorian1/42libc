/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_memdup.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:34:00 by                   #+#    #+#             */
/*   Updated: 2023/05/09 11:34:16 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MEMDUP_H
# define LIB_MEMDUP_H

# include <stddef.h>

void *_Nonnull	lib_memdup(void *_Nonnull src, void *_Nonnull dst, size_t len);

#endif
