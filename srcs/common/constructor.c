/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:55:04 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 18:14:45 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** constructs preallocated memory regions for
** tiny and small zones
*/
void	_constructor(void)
{
	if (!(count_zone_bytype(TINY)))
		m_zone_add(TINY, 0);
	if (!(count_zone_bytype(SMALL)))
		m_zone_add(SMALL, 0);
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
			m_zone_remove(head);
		head = next;
	}
}
