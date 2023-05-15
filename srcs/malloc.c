/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:11:51 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/15 18:12:22 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

t_zone	*g_zones = NULL;

void	free(void *ptr)
{
/*	ft_putstr("### free: ");
	ft_puthex((size_t)ptr);
	ft_putstr("\n");*/

	if (ptr)
		alloc_remove(ptr);
	return ;
}

/*
** Implementation defined:
** malloc(0) will return NULL.
*/
void	*malloc(size_t size)
{
/*	ft_putstr("### alloc: ");
	ft_putnbr(size);
	ft_putstr("\n");*/
	t_alloc *new_alloc;
	
	if (!(size))
		return (NULL);
	new_alloc = alloc_add(size);
	if (!(new_alloc))
		return (NULL);
	return (new_alloc->ptr);
}

void	*realloc(void *ptr, size_t size)
{
	t_alloc *new_alloc;

	if (!ptr)
		return (malloc(size));
	if (!(size))
	{
		free(ptr);
		return (ptr);
	}
	new_alloc = alloc_realloc(ptr, size);
	if (!(new_alloc))
		return (NULL);
	return (new_alloc->ptr);
}

void	show_alloc_mem(void)
{
	_print_zones();
}
