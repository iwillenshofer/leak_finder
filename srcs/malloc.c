/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:11:51 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/05 12:35:37 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_zone			*g_zones = NULL;
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	free(void *ptr)
{
	if (ptr)
	{
		lock_mutex();
		alloc_remove(ptr);
		unlock_mutex();
	}
	return ;
}

/*
** Implementation defined:
** malloc(0) will return NULL.
*/
void	*malloc(size_t size)
{
	t_alloc	*new_alloc;

	if (!(size))
		return (NULL);
	lock_mutex();
	new_alloc = alloc_add(size);
	unlock_mutex();
	if (!(new_alloc))
		return (NULL);
	return (new_alloc->ptr);
}

void	*realloc(void *ptr, size_t size)
{
	t_alloc	*new_alloc;

	if (!ptr)
		return (malloc(size));
	if (!(size))
	{
		free(ptr);
		return (NULL);
	}
	lock_mutex();
	new_alloc = alloc_realloc(ptr, size);
	unlock_mutex();
	if (!(new_alloc))
		return (NULL);
	return (new_alloc->ptr);
}

void	show_alloc_mem(void)
{
	lock_mutex();
	_print_zones();
	unlock_mutex();
}

void	show_alloc_mem_ex(void)
{
	lock_mutex();
	_print_zones_ex();
	unlock_mutex();
}
