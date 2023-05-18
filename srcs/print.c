/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:45:12 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/17 11:51:52 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

void	_print_alloc(t_alloc *alloc)
{
	ft_putchar(' ');
	if (DEBUG)
	{
		ft_color(BLACK, FAINT);
		ft_puthex((size_t)(alloc));
		ft_putchar(' ');
		ft_color(RESET, REGULAR);
	}
	ft_puthex((size_t)(alloc->ptr));
	ft_putstr(" - ");
	ft_puthex((size_t)(alloc->ptr) + alloc->size - 1);
	ft_putstr(" : ");
	ft_putnbr(alloc->size);
	ft_putstr(" bytes\n");
}

void	_print_zone(t_zone *zone)
{
	t_alloc	*alloc;

	if (zone->type == TINY)
		ft_putstr("TINY: ");
	else if (zone->type == MEDIUM)
		ft_putstr("SMALL : ");
	else
		ft_putstr("LARGE : ");
	ft_puthex((size_t)zone);
	if (DEBUG)
	{
		ft_color(CYAN, FAINT);
		ft_putchar(' ');
		ft_puthex((size_t)(zone->allocs));
		ft_putstr(" : ");
		ft_putnbr((size_t)(zone->size));
		ft_putstr(" bytes");
		ft_color(RESET, REGULAR);
	}
	ft_putchar('\n');
	alloc = zone->allocs;
	while (alloc)
	{
		_print_alloc(alloc);
		alloc = alloc->next;
	}
}

void	_print_zones(void)
{
	t_zone	*head;

	head = g_zones;
	while (head)
	{
		_print_zone(head);
		head = head->next;
	}
}











void	_print_alloc_ex(t_alloc *alloc)
{
	ft_putchar(' ');
	if (DEBUG)
	{
		ft_color(BLACK, FAINT);
		ft_putnbr((size_t)(alloc));
		ft_putstr(((size_t)(alloc) % ALIGNMENT == 0 ? "T" : "-" ));

		ft_putchar(' ');
		ft_color(RESET, REGULAR);
	}
	ft_putnbr((size_t)(alloc->ptr));
	ft_putstr(((size_t)(alloc->ptr) % ALIGNMENT == 0 ? "T" : "-" ));
	ft_putstr(" - ");
	ft_putnbr((size_t)(alloc->ptr) + alloc->size - 1);
	ft_putstr(" : ");
	ft_color(GREEN, REGULAR);
	if (alloc->size % ALIGNMENT)
		ft_color(RED, REGULAR);
	ft_putnbr(alloc->size);
	ft_putstr(" bytes\n");
	ft_color(RESET, REGULAR);
}

void	_print_zone_ex(t_zone *zone)
{
	t_alloc	*alloc;

	if (zone->type == TINY)
		ft_putstr("TINY: ");
	else if (zone->type == MEDIUM)
		ft_putstr("SMALL : ");
	else
		ft_putstr("LARGE : ");
	ft_putnbr((size_t)zone);
	ft_putstr(((size_t)(zone) % ALIGNMENT == 0 ? "T" : "-" ));
	if (DEBUG)
	{
		ft_color(CYAN, FAINT);
		ft_putchar(' ');
		ft_puthex((size_t)(zone->allocs));
		ft_putstr(((size_t)(zone->allocs) % ALIGNMENT == 0 ? "T" : "-" ));
		ft_putstr(" : ");
		ft_putnbr((size_t)(zone->size));
		ft_putstr(((size_t)(zone->size) % ALIGNMENT == 0 ? "T" : "-" ));
		ft_putstr(" bytes");
		ft_color(RESET, REGULAR);
	}
	ft_putstr(" -> ");
	ft_putnbr(zone->size / getpagesize());
	ft_putstr(" pages");
	ft_putchar('\n');
	alloc = zone->allocs;
	while (alloc)
	{
		_print_alloc_ex(alloc);
		alloc = alloc->next;
	}
}

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