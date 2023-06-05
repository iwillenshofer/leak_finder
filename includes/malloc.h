/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:21:07 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/05 18:10:39 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "malloc_internal.h"
# include "malloc_bonus.h"

void	free(void *ptr)
		__attribute__ ((visibility ("default")));

void	*malloc(size_t size)
		__attribute__ ((visibility ("default")));

void	*realloc(void *ptr, size_t size)
		__attribute__ ((visibility ("default")));

void	show_alloc_mem(void)
		__attribute__ ((visibility ("default")));

#endif
