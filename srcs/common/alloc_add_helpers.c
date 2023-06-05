/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_add_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:22:09 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/05 18:05:17 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** returns a pointer to the end of the zone node
*/
char	*_endzone(t_zone *zone)
{
	return ((char *)(zone) + _aligned_size(sizeof(t_zone)));
}

/*
** returns a pointer to the end of the alloc node
*/
char	*_endalloc(t_alloc *alloc)
{
	return ((char *)(alloc) + _aligned_size(sizeof(t_alloc)));
}

/*
** bool to check if there is free space in the middle of an allocation
** to fit size
*/
char	_is_space_middle_alloc(t_alloc *head, size_t size)
{
	return (head->next && (char *)(head->next) >= (char *)(head)
		+ (_aligned_size(sizeof(t_alloc)) * 2) + head->size + size);
}

/*
** bool to check if there is space at the end of an allocation
** to fit size
*/
char	_is_space_end_alloc(t_alloc *head, t_zone *zone, size_t size)
{
	return (!(head->next) && ((char *)(zone)
		+ zone->size >= _endalloc(head)
		+ _aligned_size(sizeof(t_alloc)) + head->size + size));
}

/*
** bool to check if there is space at the beginning of a zone
** to fit size
*/
char	_is_space_begin_zone(t_alloc *head, t_zone *zone, size_t size)
{
	return (head && head >= (t_alloc *)(_endzone(zone)
		+ _aligned_size(sizeof(t_alloc)) + size));
}
