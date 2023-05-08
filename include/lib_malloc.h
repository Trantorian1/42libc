/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_malloc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:11:58 by                   #+#    #+#             */
/*   Updated: 2023/05/08 11:48:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MALLOC_H
# define LIB_MALLOC_H

# include <stddef.h>
# include <stdbool.h>

void *_Nonnull	lib_malloc(size_t size);
void *_Nonnull	lib_realloc(void *_Nonnull mem, size_t size);
void			lib_freeall(void);
void			lib_free(void *_Nonnull mem);
bool			is_leaking(void);

#endif
