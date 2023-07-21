/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_puthex_byte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:30:03 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 17:45:08 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

void	_print_hex_byte(unsigned char c)
{
	if (c < 10)
		c += '0';
	else
		c += 'a' - 10;
	ftm_putchar(c);
}

void	ftm_puthexbyte(unsigned char c)
{
	unsigned char	n1;
	unsigned char	n2;

	n1 = c / 16;
	n2 = c % 16;
	ftm_putchar(' ');
	_print_hex_byte(n1);
	_print_hex_byte(n2);
}
