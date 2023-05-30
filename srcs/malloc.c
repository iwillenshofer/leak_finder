/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:11:51 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/30 16:28:31 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_zone	*g_zones = NULL;

void	free(void *ptr)
{
	ft_putstr("free(");
	ft_puthex((size_t)ptr);
	ft_putstr(")\n");
	if (ptr)
	{
		lock_mutex();
		alloc_remove(ptr);
		unlock_mutex();
	}
	ft_putstr("EOFREE\n");
	static int count = 0;
	count ++;
	if (count == 252)
		show_alloc_mem_ex();
	return ;
}

/*
** Implementation defined:
** malloc(0) will return NULL.
*/
void	*malloc(size_t size)
{
	t_alloc	*new_alloc;

	ft_putstr("malloc(");
	ft_putnbr(size);
	ft_putstr(")\n");
	if (!(size))
		return (NULL);
	lock_mutex();
	new_alloc = alloc_add(size);
	unlock_mutex();
	if (!(new_alloc))
		return (NULL);
	ft_putstr("--> ");
	ft_puthex((size_t)(new_alloc->ptr));
	ft_putstr("\n");	
	return (new_alloc->ptr);
}

void	*realloc(void *ptr, size_t size)
{
	t_alloc	*new_alloc;

	return(malloc(size));
	ft_putstr("realloc(");
	ft_puthex((size_t)ptr);
	ft_putstr(", ");
	ft_putnbr(size);
	ft_putstr(")\n");
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
	{
		return (malloc(size));
	}
	ft_putstr("--> ");
	ft_puthex((size_t)(new_alloc->ptr));
	ft_putstr("\n");	
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
