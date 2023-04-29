/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 13:09:03 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/29 15:47:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_malloc.h"

#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct s_mem
{
	size_t			size;
	struct s_mem	*prev;
	struct s_mem	*next;
}	t_s_mem;

static t_s_mem	*g_mem_head = NULL;

void *_Nonnull	lib_malloc(size_t size)
{
	t_s_mem	*node;

	node = malloc(sizeof(*node) + size);
	if (node == NULL)
	{
		lib_freeall();
		exit (ENOMEM);
	}
	node->size = size;
	node->prev = NULL;
	node->next = NULL;
	if (g_mem_head == NULL)
		g_mem_head = node;
	else
	{
		node->prev = g_mem_head;
		g_mem_head->next = node;
		g_mem_head = node;
	}
	return ((void *)(node + 1));
}

// TODO: implement own version of memcpy
void *_Nonnull	lib_realloc(void *_Nonnull mem, size_t size)
{
	t_s_mem		*node_old;
	t_s_mem		*node_new;
	static char	dummy = '\0';

	if (mem == NULL)
	{
		errno = EINVAL;
		return (&dummy);
	}
	node_old = ((t_s_mem *)mem) - 1;
	node_new = malloc(sizeof(*node_new) + size);
	if (node_new == NULL)
	{
		lib_freeall();
		exit(ENOMEM);
	}
	node_new->size = size;
	node_new->prev = NULL;
	node_new->next = NULL;
	memcpy(node_new, node_old, sizeof(*node_old));
	memcpy(node_new + 1, mem, node_old->size);
	if (node_old == g_mem_head)
		g_mem_head = node_new;
	free(node_old);
	return ((void *)(node_new + 1));
}

void *_Nonnull	lib_freeall(void)
{
	t_s_mem			*node_prev;
	t_s_mem			*node_curr;
	static t_s_mem	dummy = {.size = 0, .next = NULL, .prev = NULL};

	errno = ENOMEM;
	node_curr = g_mem_head;
	while (node_curr != NULL)
	{
		node_prev = node_curr;
		node_curr = node_curr->next;
		node_prev->prev = NULL;
		node_prev->next = NULL;
		free(node_prev);
	}
	g_mem_head = NULL;
	return (&dummy);
}

void	lib_free(void *_Nonnull mem)
{
	t_s_mem	*node;

	if (mem == NULL)
	{
		errno = EINVAL;
		return ;
	}
	node = ((t_s_mem *)mem) - 1;
	if (node->next)
		node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else if (node == g_mem_head)
		g_mem_head = NULL;
	node->prev = NULL;
	node->next = NULL;
	free(node);
}

bool	is_leaking(void)
{
	return (g_mem_head != NULL);
}
