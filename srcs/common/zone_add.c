/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:28:57 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 18:15:08 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** ensure size is multiple of 16 (ALIGNMENT).
*/
size_t	m_aligned_size(size_t size)
{
	size_t	rest;

	if (size < ALIGNMENT)
		return (ALIGNMENT);
	rest = size % ALIGNMENT;
	if (!rest)
		return (size);
	return (size + (ALIGNMENT - rest));
}

/*
** get_paginated_size makes sure the size requested to mmap is:
** 1. multiple of getpagesize() - this applies to all cases
** 2. fits at least 100 allocation if size is of small or tiny type.
** 3. includes the header needed for such allocations, wich means:
** - one t_zone size, and one or 100 t_alloc sizes (as in rule 2)
*/
size_t	__get_paginated_size(size_t size)
{
	size_t	amount;
	size_t	total_size;
	size_t	pagesize;

	pagesize = getpagesize();
	amount = 1;
	if (size <= SMALL_LIMIT)
		amount = 100;
	total_size = m_aligned_size(sizeof(t_zone)) + amount
		* (m_aligned_size(sizeof(t_alloc)) + ALIGNMENT);
	if (size > SMALL_LIMIT)
		total_size += size;
	else if (size > TINY_LIMIT)
		total_size += (amount * SMALL_LIMIT);
	else
		total_size += (amount * TINY_LIMIT);
	if (pagesize > total_size)
		return (pagesize);
	return (total_size + (pagesize - (total_size % pagesize)));
}

/*
** Allocation only happens on zone level.
*/

void	*__allocate(size_t size)
{
	void	*ptr;

	ptr = mmap (NULL, size,
			PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (ptr == MAP_FAILED)
		return (NULL);
	return (ptr);
}

/*
** places the newly created zone in the head (g_zone)
** if the list is still empty, or at the end of it (last element).
*/
void	__zone_place_new(t_zone *ptr)
{
	t_zone	*head;

	if (g_zones == NULL)
		g_zones = ptr;
	else
	{
		head = g_zones;
		while (head->next)
			head = head->next;
		head->next = ptr;
		ptr->prev = head;
	}
}

/*
** size is only used for LARGE allocs
** otherwise, type is used to determine the size of allocation.
** 1. create zone memory 
** 2. set up zone structure
** 3. add to the end of g_zones.
*/
t_zone	*m_zone_add(char type, size_t size)
{
	t_zone	*ptr;
	size_t	total_size;

	if (type == SMALL)
		size = SMALL_LIMIT;
	else if (type == TINY)
		size = TINY_LIMIT;
	total_size = __get_paginated_size(size);
	ptr = __allocate(total_size);
	if (!(ptr))
		return (NULL);
	ftm_bzero(ptr, m_aligned_size(sizeof(t_zone)));
	ptr->free = total_size - m_aligned_size(sizeof(t_zone));
	ptr->size = total_size;
	ptr->type = type;
	__zone_place_new(ptr);
	m_zone_sort();
	return (ptr);
}
