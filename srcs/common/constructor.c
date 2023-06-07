/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:55:04 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/07 10:48:38 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** constructs preallocated memory regions for
** tiny and small zones
*/
void	_constructor(void)
{
	if (!(_count_zone_bytype(TINY)))
		_zone_add(TINY, 0);
	if (!(_count_zone_bytype(SMALL)))
		_zone_add(SMALL, 0);
}

/*
** destroys any empty tiny and small regions.
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
			_zone_remove(head);
		head = next;
	}
}
