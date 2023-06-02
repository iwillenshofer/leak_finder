/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_realloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:46:05 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/02 15:31:50 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_zone	*find_zone(void *ptr)
{
	t_zone	*head;

	head = g_zones;
	while (head)
	{
		if ((char *)head < (char *)ptr
			&& (char *)ptr < (char *)head + head->size)
			return (head);
		head = head->next;
	}
	return (NULL);
}

t_alloc	*find_alloc(void *ptr, t_zone *zone)
{
	t_alloc	*alloc;

	if (!(ptr) || !(zone) || (zone && !(zone->allocs)))
		return (NULL);
	alloc = zone->allocs;
	while (alloc)
	{
		if (alloc->ptr == ptr)
			return (alloc);
		else if ((char *)alloc < (char *)ptr
			&& (char *)ptr < (char *)alloc + alloc->size)
			return (NULL);
		alloc = alloc->next;
	}
	return (NULL);
}

/*
** 
*/
t_alloc	*reallocate(t_alloc *alloc, size_t size)
{
	t_alloc	*new_alloc;
	size_t	limit;

	new_alloc = alloc_add(size);
	limit = size;
	if (size < alloc->size)
		limit = alloc->size;
	if (new_alloc && new_alloc->ptr)
	{
		ft_memcpy(new_alloc->ptr, alloc->ptr, limit);
		alloc_remove(alloc->ptr);
		return (new_alloc);
	}
	else
		return (NULL);
}

/*
** 
*/
t_alloc	*resize(t_alloc *alloc, size_t size)
{
	alloc->size = size;
	return (alloc);
}

/*
** case 0: if types are different, new allocation will occur!
** case 1: single allocated with space in zone (zone-type and
**  new size must match).
*/
t_alloc	*alloc_realloc(void *ptr, size_t size)
{
	char	new_type;
	t_zone	*zone;
	t_alloc	*alloc;
	t_alloc	*new_alloc;

	size = _aligned_size(size);
	new_type = get_type(size);
	zone = find_zone(ptr);
	alloc = find_alloc(ptr, zone);
	if (!zone || !alloc)
		return (NULL);
	if (new_type != zone->type)
		new_alloc = reallocate(alloc, size);
	else if (size <= alloc->size)
		new_alloc = resize(alloc, size);
	else if (_is_space_realloc_middle(alloc, size))
		new_alloc = resize(alloc, size);
	else if (_is_space_realloc_end(alloc, zone, size))
		new_alloc = resize(alloc, size);
	else
		new_alloc = reallocate(alloc, size);
	return (new_alloc);
}
