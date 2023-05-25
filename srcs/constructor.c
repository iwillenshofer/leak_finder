/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:55:04 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/24 18:33:40 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

/*
** constructs preallocated memory regions for
** small and medium zones
*/
void	_constructor(void)
{
	create_mutex();
	zone_add(TINY, 0);
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
	destroy_mutex();
}
