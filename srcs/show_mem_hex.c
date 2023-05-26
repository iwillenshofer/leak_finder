/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:45:12 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/26 17:42:22 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** prints the whole hex representation of a zone.
*/
void	_print_zone_hex(t_zone *zone)
{
	char	*addr;
	t_alloc	*next_alloc;
	char	buffer[PRINT_COLUMNS + 1];
	t_color	color;

	_clear_buffer((char *)&buffer);
	addr = (char *)zone;
	next_alloc = zone->allocs;
	while (addr < (char *)(zone) + zone->size)
	{
		_print_addr_type_color(zone, addr, next_alloc, &color);
		if (next_alloc && addr + 1 == (char *)(next_alloc->next))
			next_alloc = next_alloc->next;
		if (!((addr - (char *)zone) % PRINT_COLUMNS))
			ft_puthex((size_t)(addr));
		if (ALIGNMENT > 1 && !((addr - (char *)zone) % ALIGNMENT))
			ft_putchar(' ');
		ft_puthexbyte(*addr);
		buffer[(addr - (char *)zone) % PRINT_COLUMNS] = *addr;
		if (!((++addr - (char *)zone) % PRINT_COLUMNS))
			_print_buffer((char *)&buffer, &color);
	}
}

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
** lists usefull zone information, suchas total, used and free bytes.
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

/*
** main function to print each zone, calling information about it and
** hex representation.
*/
void	_print_zone_ex(t_zone *zone)
{
	if (zone->type == TINY)
		ft_putstr("TINY: ");
	else if (zone->type == MEDIUM)
		ft_putstr("SMALL: ");
	else
		ft_putstr("LARGE: ");
	ft_puthex((size_t)zone);
	ft_putchar(' ');
	_print_zone_information(zone);
	_print_zone_hex(zone);
	_put_color(RESET, REGULAR, NULL);
}

/*
** begin of printing zones. just a loop through all zones in the list.
*/
void	_print_zones_ex(void)
{
	t_zone	*head;

	head = g_zones;
	while (head)
	{
		_print_zone_ex(head);
		head = head->next;
	}
}
