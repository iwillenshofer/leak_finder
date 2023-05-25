/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:10:21 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/25 13:01:20 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** ensure size is at least size, and multiple of 16 (ALIGNMENT).
*/
size_t	_aligned_size(size_t size)
{
	size_t	rest;

	if (size < ALIGNMENT)
		return (ALIGNMENT);
	rest = size % ALIGNMENT;
	if (!rest)
		return (size);
	return (size + (ALIGNMENT - rest));
}
