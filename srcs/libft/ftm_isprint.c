/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftm_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:07:11 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 17:44:13 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

int	ftm_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (TRUE);
	return (FALSE);
}
