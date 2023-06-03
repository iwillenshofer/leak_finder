/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:14:02 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/03 18:18:19 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	deallocate(t_zone *zone)
{
	int res;

	res = munmap(zone, zone->size);
	if (!res)
		deallocated++;
}

void	zone_remove(t_zone *zone)
{
	t_zone	*head;

	head = g_zones;
	if (head == zone)
		g_zones = head->next;
	else
	{
		while (head && head != zone)
			head = head->next;
		if (head == zone)
			head->prev->next = head->next;
	}
	if (head->next)
		head->next->prev = head->prev;
	if (head->prev)
		head->prev->next = head->next;
	deallocate(head);
}
