/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:06:25 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/10 11:59:19 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_color(size_t color, size_t bold)
{
	ft_putstr("\033[");
	if (color)
	{
		ft_putnbr(bold);
		ft_putchar(';');
	}
	ft_putnbr(color);
	ft_putchar('m');
}
