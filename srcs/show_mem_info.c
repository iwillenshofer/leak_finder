/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:24:17 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/02 14:28:54 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** helper to the _print_zone_information() function.
** returns the count of allocations, and sets the value referenced by usedvar
** as the total count of used bytes by the allocations
** (size of alloc + size of struct + size of zone struct)
*/
size_t	_calc_allocations(t_zone *zone, size_t *usedvar)
{
	size_t	used;
	size_t	count;
	t_alloc	*allocs;

	count = 0;
	used = _aligned_size(sizeof(t_zone));
	allocs = zone->allocs;
	while (allocs)
	{
		count++;
		used += (allocs->size + _aligned_size(sizeof(t_alloc)));
		allocs = allocs->next;
	}
	if (usedvar)
		*usedvar = used;
	return (count);
}

/*
** lists usefull zone information, such as total, used and free bytes.
*/
void	_print_zone_information(t_zone *zone)
{
	size_t	used;
	size_t	count;

	count = _calc_allocations(zone, &used);
	ft_putnbr((size_t)(zone->size));
	ft_putstr(" allocated bytes. ");
	_put_color(GREEN, REGULAR, NULL);
	ft_putnbr(zone->size - used);
	ft_putstr(" free bytes. ");
	_put_color(RED, REGULAR, NULL);
	ft_putnbr(used);
	ft_putstr(" used bytes. ");
	_put_color(YELLOW, REGULAR, NULL);
	ft_putnbr(count);
	ft_putstr(" allocations. ");
	_put_color(PURPLE, REGULAR, NULL);
	if (zone->type == TINY)
		ft_putnbr(TINY_LIMIT);
	else if (zone->type == MEDIUM)
		ft_putnbr(MEDIUM_LIMIT);
	else
		ft_putstr("undetermined");
	ft_putstr(" bytes max alloc. ");
	ft_putchar('\n');
}
