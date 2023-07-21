/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem_ex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:45:12 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 12:48:30 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_bonus.h"
/*
** prints the whole hex representation of a zone.
*/

t_bool	check_last_pos(t_zone *zone, char *addr)
{
	t_alloc	*head;
	char	*pos;

	if (!DEBUG)
		return (false);
	pos = NULL;
	head = zone->allocs;
	while (head)
	{
		pos = ((char *)(head)) + head->size + sizeof(t_alloc);
		head = head->next;
	}
	if (!pos)
		pos = ((char *)(zone)) + sizeof(t_zone);
	if (addr > pos)
	{
		ft_puthex((size_t)(addr));
		ft_putstr("  ... NO MORE ALLOCATIONS\n");
		ft_puthex((size_t)((char *)zone + zone->size - 1));
		ft_putstr("  [END OF ZONE]\n\n");
		return (true);
	}
	return (false);
}

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
		if (!((addr - (char *)zone) % PRINT_COLUMNS))
			ft_puthex((size_t)(addr));
		if (ALIGNMENT > 1 && !((addr - (char *)zone) % ALIGNMENT))
			ft_putchar(' ');
		ft_puthexbyte(*addr);
		buffer[(addr - (char *)zone) % PRINT_COLUMNS] = *addr;
		if (next_alloc && addr + 1 == (char *)(next_alloc->next))
			next_alloc = next_alloc->next;
		if (!((++addr - (char *)zone) % PRINT_COLUMNS))
			_print_buffer((char *)&buffer, &color);
		if (!((addr - (char *)zone) % PRINT_COLUMNS)
			&& check_last_pos(zone, addr))
			break ;
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
	else if (zone->type == SMALL)
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
	_put_color(RESET, REGULAR, NULL);
	while (head)
	{
		if (head->type == TINY)
			ft_putstr("TINY: ");
		else if (head->type == SMALL)
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
	_put_color(RESET, REGULAR, NULL);
	while (head)
	{
		_print_zone_ex(head);
		head = head->next;
	}
}
