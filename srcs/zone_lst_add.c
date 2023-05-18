/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_lst_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:28:57 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/17 15:34:17 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

/*
** get_paginated_size makes sure the size requested to mmap is:
** 1. multiple of getpagesize() - this applies to all cases
** 2. fits at least 100 allocation if size is of medium or tiny type.
** 3. includes the header needed for such allocations, wich means:
** - one t_zone size, and one or 100 t_alloc sizes (as in rule 2)
*/

size_t get_paginated_size(size_t size)
{
	size_t amount;
	size_t total_size;
	size_t pagesize;

	pagesize = getpagesize();
	amount = (size > MEDIUM_LIMIT) ? 1 : 100;
	total_size = _aligned_size(sizeof(t_zone)) + amount * (_aligned_size(sizeof(t_alloc)) + ALIGNMENT);
	if (size > MEDIUM_LIMIT)
		total_size += size;
	else if (size > TINY_LIMIT)
		total_size += (amount * MEDIUM_LIMIT);
	else
		total_size += (amount * TINY_LIMIT);
	if (pagesize > total_size)
		return (pagesize);
	return (total_size + (pagesize - (total_size % pagesize)));
}

/*
** Allocation only happens on zone level.
*/
void    *allocate(size_t size)
{
	void *ptr;
	/*
	** TODO: SOME ERROR TREATMENT HERE, IN CASE ALLOCATION WAS NOT SUCCESSFULL.
	*/
	ptr = mmap ( NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0 );
	return (ptr);
}

/*
** size is only used for LARGE allocs
** otherwise, type is used to determine the size of allocation.
*/
t_zone *zone_add(char type, size_t size)
{
	/*1. create zone memory */
	t_zone *ptr;
	t_zone *head;
	size_t total_size;

	if (type == MEDIUM)
		size = MEDIUM_LIMIT;
	else if (type == TINY)
		size = TINY_LIMIT;
	total_size = get_paginated_size(size);
	ptr = allocate(total_size);
	
	/*2. set up zone structure*/
	ft_bzero(ptr, _aligned_size(sizeof(t_zone)));
	ptr->size = total_size;
	ptr->type = type;
	/*3. add to the end of g_zones.*/
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
	return (ptr);
}
