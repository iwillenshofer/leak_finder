/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:09:02 by iwillens          #+#    #+#             */
/*   Updated: 2023/01/01 12:23:13 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_loop(size_t nb)
{
	char	c;

	if ((nb / 16))
		ft_puthex_loop(nb / 16);
	c = (nb % 16);
	if (c < 10)
		c += '0';
	else
		c = (c - 10) + 'a';
	ft_putchar(c);
}

void	ft_puthex(size_t nb)
{
	ft_putstr("0x");
	ft_puthex_loop(nb);
}
