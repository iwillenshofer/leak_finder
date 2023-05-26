/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_byte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:30:03 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/26 17:33:07 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	_print_hex_byte(unsigned char c)
{
	if (c < 10)
		c += '0';
	else
		c += 'a' - 10;
	ft_putchar(c);
}

void	ft_puthexbyte(unsigned char c)
{
	unsigned char	n1;
	unsigned char	n2;

	n1 = c / 16;
	n2 = c % 16;
	ft_putchar(' ');
	_print_hex_byte(n1);
	_print_hex_byte(n2);
}
