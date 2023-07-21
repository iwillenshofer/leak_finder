/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:04:13 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 11:38:13 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_bonus.h"

/*
** prints a new color only if it is different of the previous color
** (or there is no previous color.).
** Then, it current color exists, sets it to the new values.
*/
void	_put_color(char new_color, char new_opt, t_color *current)
{
	if (current && current->color == new_color && current->options == new_opt)
		return ;
	if (new_color == RESET)
	{
		ft_putstr("\033[0m");
		return ;
	}
	ft_putstr("\033[0;");
	if (new_color)
	{
		ft_putnbr(new_opt);
		ft_putchar(';');
	}
	ft_putnbr(new_color);
	ft_putchar('m');
	if (current)
	{
		current->color = new_color;
		current->options = new_opt;
	}
}

/*
** when printing bytes, this function determines what color it should be,
** according to *addr relative position to *zone and allocations.
** 1. first byte of the zone header = bold white;
** 2. remaining bytes of the zone header = regular white;
** 3. first byte of alloc headers = bold cyan;
** 4. remaining bytes of alloc headers = regular cyan;
** 5. user allocated bytes = faint cyan.
** 6. free bytes within zone = faint white.
** returns false if address is not allocated.
** otherwise returns true.
*/
t_bool	_print_addr_type_color(t_zone *zone, char *addr,
		t_alloc *next_alloc, t_color *color)
{
	if (addr == (char *)zone)
		_put_color(WHITE, BOLD, color);
	else if (addr > (char *)zone && addr
		< (char *)zone + _aligned_size(sizeof(t_zone)))
		_put_color(WHITE, REGULAR, color);
	else if (next_alloc && addr == (char *)next_alloc)
		_put_color(CYAN, BOLD, color);
	else if (next_alloc && addr > (char *)next_alloc
		&& addr < (char *)(next_alloc->ptr))
		_put_color(CYAN, REGULAR, color);
	else if (next_alloc && addr > (char *)next_alloc
		&& addr < (char *)next_alloc->ptr + next_alloc->size)
		_put_color(CYAN, FAINT, color);
	else
	{
		_put_color(WHITE, FAINT, color);
		return (false);
	}
	return (true);
}
