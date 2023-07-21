/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:45:12 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 18:16:53 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** prints allocation info, as required by the subject
*/
void	__print_alloc(t_alloc *alloc)
{
	ftm_puthex((size_t)(alloc->ptr));
	ftm_putstr(" - ");
	ftm_puthex((size_t)(alloc->ptr) + alloc->size - 1);
	ftm_putstr(" : ");
	ftm_putnbr(alloc->size);
	ftm_putstr(" bytes\n");
}

/*
** prints zone info, as required by the subject
** returns the sum of bytes for each allocation, so it can sum at the end
*/
size_t	__print_zone(t_zone *zone)
{
	t_alloc	*alloc;
	size_t	count;

	count = 0;
	if (zone->type == TINY)
		ftm_putstr("TINY : ");
	else if (zone->type == SMALL)
		ftm_putstr("SMALL : ");
	else
		ftm_putstr("LARGE : ");
	ftm_puthex((size_t)zone);
	ftm_putchar('\n');
	alloc = zone->allocs;
	while (alloc)
	{
		__print_alloc(alloc);
		count += alloc->size;
		alloc = alloc->next;
	}
	return (count);
}

/*
** loops through zone, printing each info
*/
void	m_print_zones(void)
{
	t_zone	*head;
	size_t	count;

	count = 0;
	head = g_zones;
	while (head)
	{
		count += __print_zone(head);
		head = head->next;
	}
	ftm_putstr("Total : ");
	ftm_putnbr(count);
	ftm_putstr(" bytes\n");
}
