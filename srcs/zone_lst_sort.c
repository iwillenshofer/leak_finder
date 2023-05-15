/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_lst_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 00:14:02 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/10 12:01:41 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

/*
** Sorting zones may be needed to make sure they are ordered
** according to their address.
*/

/*
** swaps self with self->next. 
*/
void	swap(t_zone *self)
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

void	zone_sort(void)
{
	t_zone	*head;

	head = g_zones;
	while (head && head->next)
	{
		if (head < head->next)
		{
			swap(head);
			head = g_zones;
		}
		else
			head = head->next;
	}
}
