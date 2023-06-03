/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_realloc_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:01:02 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/03 15:18:17 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** returns true if there is the space required by size between current and
** next allocation.
*/
char	_is_space_realloc_middle(t_alloc *alloc, size_t size)
{
	return (alloc->next
		&& (size_t)((char *)(alloc->next) - _endalloc(alloc)) >= size);
}

/*
** returns true if there is no next allocation, and there is enough space
** between current alloc and the required size.
*/
char	_is_space_realloc_end(t_alloc *alloc, t_zone *zone, size_t size)
{
	return (!(alloc->next)
		&& zone->size - (_endalloc(alloc) - (char*)(zone)) >= size);
}
