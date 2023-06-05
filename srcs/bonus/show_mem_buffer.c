/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:06:03 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/05 17:19:18 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_bonus.h"

void	_clear_buffer(char *s)
{
	ft_bzero(s, PRINT_COLUMNS);
}

/*
** Prints black '.' if character is not
** printable, and the white character if it is.
** changes the color of print if needed. 
*/
void	_print_buffer_digit(char c, t_color *color)
{
	if (ft_isprint(c))
	{
		_put_color(WHITE, REGULAR, color);
		ft_putchar(c);
	}
	else
	{
		_put_color(BLACK, REGULAR, color);
		ft_putchar('.');
	}
}

/*
** Prints the buffer (digit representation of the hexa mem).
** Since the colors are beeing written for the hex representation,
** and we are changing the color here, the color is changed back to
** the previous one.
*/
void	_print_buffer(char *s, t_color *color)
{
	size_t	i;
	t_color	prev_color;

	prev_color.color = color->color;
	prev_color.options = color->options;
	i = 0;
	ft_putstr("  ");
	while (i < PRINT_COLUMNS)
	{
		_print_buffer_digit(s[i], color);
		i++;
	}
	_put_color(prev_color.color, prev_color.options, color);
	ft_putchar('\n');
	_clear_buffer(s);
}
