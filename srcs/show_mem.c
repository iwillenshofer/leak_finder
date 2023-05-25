/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:45:12 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/25 14:23:21 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	_print_alloc(t_alloc *alloc)
{
	ft_puthex((size_t)(alloc->ptr));
	ft_putstr(" - ");
	ft_puthex((size_t)(alloc->ptr) + alloc->size - 1);
	ft_putstr(" : ");
	ft_putnbr(alloc->size);
	ft_putstr(" bytes\n");
}

/*
** returns the sum of bytes for each allocation
*/
size_t	_print_zone(t_zone *zone)
{
	t_alloc	*alloc;
	size_t	count;

	count = 0;
	if (zone->type == TINY)
		ft_putstr("TINY : ");
	else if (zone->type == MEDIUM)
		ft_putstr("SMALL : ");
	else
		ft_putstr("LARGE : ");
	ft_puthex((size_t)zone);
	ft_putchar('\n');
	alloc = zone->allocs;
	while (alloc)
	{
		_print_alloc(alloc);
		count += alloc->size;
		alloc = alloc->next;
	}
	return (count);
}

void	_print_zones(void)
{
	t_zone	*head;
	size_t	count;

	count = 0;
	head = g_zones;
	while (head)
	{
		count += _print_zone(head);
		head = head->next;
	}
	ft_putstr("Total : ");
	ft_putnbr(count);
	ft_putstr(" bytes\n");
}
