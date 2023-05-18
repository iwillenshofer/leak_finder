/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_lst_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:18:20 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/17 00:08:48 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

char    get_type(size_t size)
{
	if (size > MEDIUM_LIMIT)
		return (LARGE);
	if (size > TINY_LIMIT)
		return (MEDIUM);
	return (TINY);
}

t_alloc *create_alloc(t_alloc *pos, t_alloc *prev, t_alloc *next, size_t size)
{
	pos->size = size;
	pos->ptr = ((char*)pos + sizeof(t_alloc));
	pos->prev = NULL;
	pos->next = NULL;
	if (prev)
	{
		pos->prev = prev;
		prev->next = pos;
	}
	if (next)
	{
		pos->next = next;
		next->prev = pos;
	}
	return (pos);
}

/*
** returns null if no spot was created
*/
t_alloc *find_spot(t_zone *zone, size_t size)
{
	t_alloc *allocated;
	t_alloc *head;

	allocated = NULL;
	head = zone->allocs;
	if (!(head))
		allocated = create_alloc((t_alloc*)((char*)(zone) + _aligned_size(sizeof(t_zone))), NULL, NULL, size);
	else if (head && head > (t_alloc*)((char*)(zone) + _aligned_size(sizeof(t_zone)) + _aligned_size(sizeof(t_alloc)) + size))
		allocated = create_alloc((t_alloc*)((char*)(zone) + _aligned_size(sizeof(t_zone))), NULL, zone->allocs, size);    
	if (allocated && !(zone->allocs))
		zone->allocs = allocated; /*in case the 1st position is changed*/
	while (!(allocated) && head)
	{
		if (head->next && (char*)(head->next) > (char*)(head) + (_aligned_size(sizeof(t_alloc)) * 2) + head->size + size)
			allocated = create_alloc((t_alloc*)((char*)(head) + _aligned_size(sizeof(t_alloc)) + head->size), head, head->next, size);   
		else if (!(head->next) && ((char*)(zone) + zone->size > (char*)(head) + _aligned_size(sizeof(t_alloc)) * 2 + head->size  + size))
			allocated = create_alloc((t_alloc*)((char*)(head) + head->size + _aligned_size(sizeof(t_alloc))), head, NULL, size);
		head = head->next;
	}
	return (allocated);
}

/*
** allocation cases in order of checking:
** 1. allocation is empty, so there's definetly space
** 2. first alloc has been freed before, which means that 
** zone->alloc does not refer to the first possible allocation
** but to the first real allocation.
** 3. there's allocation space in the end.
** 4. some elements in the middle have been freed, so there is space
** between alloc and alloc->next
*/
t_alloc *alloc_add(size_t size)
{
	/*1. determine type*/
	char type;
	size = _aligned_size(size);
	type = get_type(size);
	t_zone *zone = g_zones;
	t_alloc *allocated;
	allocated = NULL;
	/*
	** 2. loop through the zones of the determined type
	** and then the allocations within that zone to find the minimum space
	** where the required allocation can fit.
	*/
	while (zone && !(allocated) && type != LARGE)
	{
		if (zone->type == type)
			allocated = find_spot(zone, size);
		zone = zone->next;
	}

	/*
	** 3. if not found, create a zone.
	** 4. Create an allocation on the available space.
	*/
	if (!(allocated))
	{
		zone = zone_add(type, size);
		allocated = find_spot(zone, size);
		if (zone)
			zone->allocs = allocated;
	}

	/*
	** return the pointer.`
	*/
	return (allocated);
}
