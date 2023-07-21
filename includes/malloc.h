/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:21:07 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 17:35:05 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "malloc_internal.h"
# include "malloc_bonus.h"

# define RECORD_BUFFER 1024

# define ACTION_REMOVE 0
# define ACTION_ADD 1

typedef struct s_info
{
	size_t		size;
	char		*address;
	const char	*file;
	const char	*function;
	int			line;
}	t_info;

# define malloc(a) _malloc(a, _info(__FILE__, __FUNCTION__, __LINE__))
# define free(a) _free(a, _info(__FILE__, __FUNCTION__, __LINE__))
# define realloc(a, b) _realloc(a, b, _info(__FILE__, __FUNCTION__, __LINE__))
# define calloc(a, b) _calloc(a, b, _info(__FILE__, __FUNCTION__, __LINE__))

t_info	_info(const char *file, const char *function, int line)
		__attribute__ ((visibility ("default")));

void	_free(void *ptr, t_info info)
		__attribute__ ((visibility ("default")));

void	*_malloc(size_t size, t_info info)
		__attribute__ ((visibility ("default")));

void	*_realloc(void *ptr, size_t size, t_info info)
		__attribute__ ((visibility ("default")));

void	*_calloc(size_t count, size_t size, t_info info)
		__attribute__ ((visibility ("default")));

void	show_alloc_mem(void)
		__attribute__ ((visibility ("default")));

void	print_leaks(void)
		__attribute__ ((visibility ("default")));

#endif
