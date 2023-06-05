/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:55:04 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/05 15:21:29 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

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
