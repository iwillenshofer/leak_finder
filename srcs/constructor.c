/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:55:04 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/02 14:17:48 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

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
** constructs preallocated memory regions for
** small and medium zones
*/
void	_constructor(void)
{
	if (!(_count_zone_bytype(TINY)))
		zone_add(TINY, 0);
	if (!(_count_zone_bytype(MEDIUM)))
		zone_add(MEDIUM, 0);
}

/*
** destroys any empty medium and small regions.
*/
void	_destructor(void)
{
	t_zone	*head;
	t_zone	*next;

	head = g_zones;
	while (head)
	{
		next = head->next;
		if (head->type != LARGE && head->allocs == NULL)
			zone_remove(head);
		head = next;
	}
}
