/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:18:01 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/05 15:25:04 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** returns how many zones of a certain type there are.
*/

size_t	_count_zone_bytype(char type)
{
	t_zone	*head;
	size_t	count;

	count = 0;
	head = g_zones;
	while (head)
	{
		if (head->type == type)
			count++;
		head = head->next;
	}
	return (count);
}

/*
** dettaches allocation from list, and deallocates zone, if it is now empty.
*/
void	free_alloc(t_alloc *alloc, t_zone *zone)
{
	if (alloc->prev)
		alloc->prev->next = alloc->next;
	if (alloc->next)
		alloc->next->prev = alloc->prev;
	if (zone->allocs == alloc)
		zone->allocs = alloc->next;
	if (!(alloc->next) && !(alloc->prev)
		&& (zone-> type == LARGE || _count_zone_bytype(zone->type) > 1))
		zone_remove(zone);
}

/*
** loop through the zones to find the allocation.
*/
void	alloc_remove(void *ptr)
{
	t_zone	*zone;
	t_alloc	*alloc;

	zone = g_zones;
	while (zone)
	{
		alloc = zone->allocs;
		if ((char *)zone < (char *)ptr
			&& (char *)ptr < (char *)zone + zone->size)
		{
			while (alloc)
			{
				if (alloc->ptr == ptr)
				{
					free_alloc(alloc, zone);
					return ;
				}
				else if ((char *)ptr > (char *)alloc
					&& (char *)ptr < ((char *)(alloc->ptr) + alloc->size))
					return ;
				alloc = alloc->next;
			}
		}
		zone = zone->next;
	}
}
