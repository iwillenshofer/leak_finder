/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem_ex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:45:12 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/05 17:19:24 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_bonus.h"

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

void	_print_zones_resume(void)
{
	t_zone	*head;

	head = g_zones;
	_put_color(BLUE, BOLD, NULL);
	ft_putstr("Overall Zones Information:\n");
	while (head)
	{
		if (head->type == TINY)
			ft_putstr("TINY: ");
		else if (head->type == MEDIUM)
			ft_putstr("SMALL: ");
		else
			ft_putstr("LARGE: ");
		ft_puthex((size_t)head);
		ft_putchar(' ');
		_print_zone_information(head);
		head = head->next;
	}
	ft_putstr("\n\n");
	_put_color(RESET, REGULAR, NULL);
}

/*
** begin of printing zones. just a loop through all zones in the list.
*/
void	_print_zones_ex(void)
{
	t_zone	*head;

	head = g_zones;
	_print_zones_resume();
	_put_color(BLUE, BOLD, NULL);
	ft_putstr("Individual Zone Information:\n");
	while (head)
	{
		_print_zone_ex(head);
		head = head->next;
	}
}
