/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:24:17 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 18:16:28 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_bonus.h"

/*
** helper to the m_print_zone_information() function.
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
	used = m_aligned_size(sizeof(t_zone));
	allocs = zone->allocs;
	while (allocs)
	{
		count++;
		used += (allocs->size + m_aligned_size(sizeof(t_alloc)));
		allocs = allocs->next;
	}
	if (usedvar)
		*usedvar = used;
	return (count);
}

/*
** lists usefull zone information, such as total, used and free bytes.
*/
void	m_print_zone_information(t_zone *zone)
{
	size_t	used;
	size_t	count;

	count = _calc_allocations(zone, &used);
	ftm_putnbr((size_t)(zone->size));
	ftm_putstr(" allocated bytes. ");
	m_put_color(GREEN, REGULAR, NULL);
	ftm_putnbr(zone->size - used);
	ftm_putstr(" free bytes. ");
	m_put_color(RED, REGULAR, NULL);
	ftm_putnbr(used);
	ftm_putstr(" used bytes. ");
	m_put_color(YELLOW, REGULAR, NULL);
	ftm_putnbr(count);
	ftm_putstr(" allocations. ");
	m_put_color(PURPLE, REGULAR, NULL);
	if (zone->type == TINY)
		ftm_putnbr(TINY_LIMIT);
	else if (zone->type == SMALL)
		ftm_putnbr(SMALL_LIMIT);
	else
		ftm_putstr("undetermined");
	ftm_putstr(" bytes max alloc. ");
	ftm_putchar('\n');
	m_put_color(RESET, REGULAR, NULL);
}
