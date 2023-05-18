/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:21:07 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/17 01:30:55 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include "../srcs/libft/libft.h"

# define TINY 0
# define MEDIUM 1
# define LARGE 2

# define TINY_LIMIT 993
# define MEDIUM_LIMIT (15 * 1024) - 1

# define ALIGNMENT 16
# define DEBUG 1

/*
** Linked List Structure for ALLOC - 2nd level
** ptr: pointer to the memory head (value returned to the user)
**  a.k.a (*t_alloc + sizeof(t_alloc))
** size: the size of this allocation.
**  not includes the size of t_alloc itself.
** next/prev: list references
*/

typedef struct s_alloc
{
    void *ptr;
    size_t size;
    struct s_alloc *prev;
    struct s_alloc *next;
}   t_alloc;

/*
** Linked List Structure for ZONE - 1st level
** allocs: pointer to the allocation head
**  a.k.a (*t_zone + sizeof(t_zone))
** size: the whole size of allocation for this Zone.
**  this includes the size of t_zone itself.
** type: TINY/MEDIUM/LARGE
** count: quantity of allocated zones.
** next: this one is obvious
** prev: also obvious, not really needed, but makes sorting easier
*/

typedef struct s_zone
{
    t_alloc *allocs;
    size_t size;
    char type;
    struct s_zone *prev;
    struct s_zone *next;
}   t_zone;

t_zone* g_zones;

__attribute__ ((visibility ("default")))
void free(void *ptr);

__attribute__ ((visibility ("default")))
void *malloc(size_t size);

__attribute__ ((visibility ("default")))
void *realloc(void *ptr, size_t size);

__attribute__ ((visibility ("default")))
void     show_alloc_mem(void);

__attribute__ ((visibility ("default")))
void     show_alloc_mem_ex(void);

t_zone *zone_add(char type, size_t size);
void    zone_remove(t_zone *zone);
void    zone_sort(void);
t_alloc *alloc_add(size_t size);
void alloc_remove(void *ptr);
t_alloc *alloc_realloc(void *ptr, size_t size);
void	_print_zones(void);
void	_print_zones_ex(void);

/*
** helpers
*/
char    get_type(size_t size);
size_t _aligned_size(size_t size);

/*
** constructor && destructor 
*/
void			_constructor(void) __attribute__((constructor));
void			_destructor(void) __attribute__((destructor));

#endif
