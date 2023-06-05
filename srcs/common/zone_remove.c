/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:14:02 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/05 18:08:19 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** call to munmap to remove the allocated zone
*/
void	deallocate(t_zone *zone)
{
	munmap(zone, zone->size);
}

/*
** detaches the zone from the list and remove it
*/
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
