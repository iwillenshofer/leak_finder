/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:21:07 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 20:18:54 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

/*
** prevents the original malloc from being included, to avoid function
** definition conflict. there may be a better way to do that.
*/

#ifndef _MALLOC_UNDERSCORE_MALLOC_H_
#  define _MALLOC_UNDERSCORE_MALLOC_H_
# endif


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

# define malloc(a) m_malloc(a, info(__FILE__, __FUNCTION__, __LINE__))
# define free(a) m_free(a, info(__FILE__, __FUNCTION__, __LINE__))
# define realloc(a, b) m_realloc(a, b, info(__FILE__, __FUNCTION__, __LINE__))
# define calloc(a, b) m_calloc(a, b, info(__FILE__, __FUNCTION__, __LINE__))

t_info	info(const char *file, const char *function, int line)
		__attribute__ ((visibility ("default")));

void	m_free(void *ptr, t_info info)
		__attribute__ ((visibility ("default")));

void	*m_malloc(size_t size, t_info info)
		__attribute__ ((visibility ("default")));

void	*m_realloc(void *ptr, size_t size, t_info info)
		__attribute__ ((visibility ("default")));

void	*m_calloc(size_t count, size_t size, t_info info)
		__attribute__ ((visibility ("default")));

void	show_alloc_mem(void)
		__attribute__ ((visibility ("default")));

void	print_leaks(void)
		__attribute__ ((visibility ("default")));

#endif
