/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 11:08:35 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 17:45:08 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

void	ftm_putnbr(int nb)
{
	unsigned int	number;

	if (nb < 0)
	{
		ftm_putchar('-');
		number = nb * -1;
	}
	else
		number = nb;
	if ((number / 10) > 0)
		ftm_putnbr(number / 10);
	ftm_putchar((number % 10) + '0');
}
