/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:09:02 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 17:45:08 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

void	ftm_puthex_loop(size_t nb)
{
	char	c;

	if ((nb / 16))
		ftm_puthex_loop(nb / 16);
	c = (nb % 16);
	if (c < 10)
		c += '0';
	else
		c = (c - 10) + 'a';
	ftm_putchar(c);
}

void	ftm_puthex(size_t nb)
{
	ftm_putstr("0x");
	ftm_puthex_loop(nb);
}
