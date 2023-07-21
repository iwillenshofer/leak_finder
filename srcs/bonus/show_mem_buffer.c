/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:06:03 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 18:16:28 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_bonus.h"

void	m_clear_buffer(char *s)
{
	ftm_bzero(s, PRINT_COLUMNS);
}

/*
** Prints black '.' if character is not
** printable, and the white character if it is.
** changes the color of print if needed. 
*/
void	m_print_buffer_digit(char c, t_color *color)
{
	if (ftm_isprint(c))
	{
		m_put_color(WHITE, REGULAR, color);
		ftm_putchar(c);
	}
	else
	{
		m_put_color(BLACK, REGULAR, color);
		ftm_putchar('.');
	}
}

/*
** Prints the buffer (digit representation of the hexa mem).
** Since the colors are beeing written for the hex representation,
** and we are changing the color here, the color is changed back to
** the previous one.
*/
void	m_print_buffer(char *s, t_color *color)
{
	size_t	i;
	t_color	prev_color;

	prev_color.color = color->color;
	prev_color.options = color->options;
	i = 0;
	ftm_putstr("  ");
	while (i < PRINT_COLUMNS)
	{
		m_print_buffer_digit(s[i], color);
		i++;
	}
	m_put_color(prev_color.color, prev_color.options, color);
	ftm_putchar('\n');
	m_clear_buffer(s);
}
