/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:58:35 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/10 11:58:59 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void print_zone(t_zone *zone)
{
	ft_puthex((size_t)zone);
	ft_putchar('\n');
	ft_putstr("-> allocs: ");
	ft_puthex((size_t)(zone->allocs));
	ft_putchar('\n');
	ft_putstr("-> size: ");
	ft_putnbr(zone->size);
	ft_putchar('\n');
	ft_putstr("-> type: ");
	ft_putnbr((size_t)(zone->type));
	ft_putchar('\n');
	ft_putstr("-> prev: ");
	ft_puthex((size_t)(zone->prev));
	ft_putchar('\n');
	ft_putstr("-> next: ");
	ft_puthex((size_t)(zone->next));
	ft_putchar('\n');
}

	t_alloc *allocs;
	size_t size;
	char type;
	struct s_zone *next;

void print_zones(void)
{
	t_zone *head;

	head = g_zones;
	while (head)
	{
		print_zone(head);
		head = head->next;
	}
}
