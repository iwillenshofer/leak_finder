/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_add_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:22:09 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/21 16:42:44 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

char	*_endzone(t_zone *zone)
{
	return ((char *)(zone) + _aligned_size(sizeof(t_zone)));
}

char	*_endalloc(t_alloc *alloc)
{
	return ((char *)(alloc) + _aligned_size(sizeof(t_alloc)));
}

char	_is_space_middle_alloc(t_alloc *head, size_t size)
{
	return (head->next && (char *)(head->next) > (char *)(head)
		+ (_aligned_size(sizeof(t_alloc)) * 2) + head->size + size);
}

char	_is_space_end_alloc(t_alloc *head, t_zone *zone, size_t size)
{
	return (!(head->next) && ((char *)(zone)
		+ zone->size > _endalloc(head)) * 2 + head->size + size);
}

char	_is_space_begin_zone(t_alloc *head, t_zone *zone, size_t size)
{
	return (head && head > (t_alloc *)(_endzone(zone)
		+ _aligned_size(sizeof(t_alloc)) + size));
}
