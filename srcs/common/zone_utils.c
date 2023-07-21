/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:14:02 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 18:15:08 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** loops through zones until finding one where ptr belongs to.
** (it does not mean that ptr is a valid ptr belonging to the user, as it may
** lie in zone/alloc headers or a zone free space, or even 'in between'
** valid allocations. ie: ptr = malloc(10); ptr + 15;)
*/
t_zone	*m_find_zone(void *ptr)
{
	t_zone	*head;

	head = g_zones;
	while (head)
	{
		if ((char *)head < (char *)ptr
			&& (char *)ptr < (char *)head + head->size)
			return (head);
		head = head->next;
	}
	return (NULL);
}

/*
** swaps self with self->next. 
*/
void	__swap(t_zone *self)
{
	t_zone	*nextnext_tmp;
	t_zone	*next;

	if (!(self->next))
		return ;
	next = self->next;
	nextnext_tmp = self->next->next;
	next->next = self;
	next->prev = self->prev;
	self->prev = next;
	self->next = nextnext_tmp;
	if (next->prev)
		next->prev->next = next;
	if (self->next)
		self->next->prev = self;
	if (g_zones == self)
		g_zones = next;
}

/*
** Sorting zones may be needed to make sure they are ordered
** according to their address (as required by the subject when printing). 
*/
void	m_zone_sort(void)
{
	t_zone	*head;

	head = g_zones;
	while (head && head->next)
	{
		if (head > head->next)
		{
			__swap(head);
			head = g_zones;
		}
		else
			head = head->next;
	}
}
