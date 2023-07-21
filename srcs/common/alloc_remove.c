/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:18:01 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 18:14:45 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** returns how many zones of a certain type there are.
*/
size_t	count_zone_bytype(char type)
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
void	__free_alloc(t_alloc *alloc, t_zone *zone)
{
	if (alloc->prev)
		alloc->prev->next = alloc->next;
	if (alloc->next)
		alloc->next->prev = alloc->prev;
	if (zone->allocs == alloc)
		zone->allocs = alloc->next;
	zone->free += (alloc->size + m_aligned_size(sizeof(t_alloc)));
	if (!(alloc->next) && !(alloc->prev)
		&& (zone-> type == LARGE || count_zone_bytype(zone->type) > 1))
		m_zone_remove(zone);
}

/*
** loop through the zones to find the allocation.
*/
void	m_alloc_remove(void *ptr)
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
					__free_alloc(alloc, zone);
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
