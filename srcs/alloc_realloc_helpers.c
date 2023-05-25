/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_realloc_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:01:02 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/25 13:01:20 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

char	_is_space_realloc_middle(t_alloc *alloc, size_t size)
{
	return (alloc->next
		&& (size_t)((char *)(alloc->next) - _endalloc(alloc)) >= size);
}

char	_is_space_realloc_end(t_alloc *alloc, t_zone *zone, size_t size)
{
	return (!(alloc->next)
		&& zone->size - (_endalloc(alloc) - (char*)(zone)) >= size);
}
