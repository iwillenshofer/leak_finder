/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:11:51 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/21 16:24:14 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

t_zone	*g_zones = NULL;

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
		return (ptr);
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
