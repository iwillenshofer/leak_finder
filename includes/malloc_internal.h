/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:45:36 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/06 09:45:42 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_INTERNAL_H
# define MALLOC_INTERNAL_H

# include <sys/mman.h>
# include "../srcs/libft/libft.h"

/*
** Zone type enum
*/
# define TINY 0
# define MEDIUM 1
# define LARGE 2

/*
** Node size limit
** Maximum size of element that will fit in a zone.
*/
# define TINY_LIMIT 256
# define MEDIUM_LIMIT 1024

/*
** Pointers must be a multiple of alignment
*/
# define ALIGNMENT 16

/*
** common definitions
*/
# define TRUE 1
# define FALSE 0

/*
** Linked List Structure for ALLOC - 2nd level
** ptr: pointer to the memory head (value returned to the user)
**  a.k.a (*t_alloc + sizeof(t_alloc))
** size: the size of this allocation.
**  does not includes the size of t_alloc itself.
** next/prev: list references
*/

typedef struct s_alloc
{
	void			*ptr;
	size_t			size;
	struct s_alloc	*prev;
	struct s_alloc	*next;
}	t_alloc;

/*
** Linked List Structure for ZONE - 1st level
** allocs: pointer to the allocation head
**  a.k.a (*t_zone + sizeof(t_zone))
** size: the whole size of allocation for this Zone.
**  this includes the size of t_zone itself.
** type: TINY/MEDIUM/LARGE
** count: quantity of allocated zones.
** next/prev: pointers to other next/prev nodes
*/

typedef struct s_zone
{
	t_alloc			*allocs;
	size_t			size;
	char			type;
	struct s_zone	*prev;
	struct s_zone	*next;
}	t_zone;

/*
** global variable for zones (allocations).
*/
t_zone			*g_zones;

/*
** main internal functions
*/
t_alloc	*_alloc_add(size_t size);
void	_alloc_remove(void *ptr);
t_alloc	*_alloc_realloc(void *ptr, size_t size);
t_zone	*_zone_add(char type, size_t size);
void	_zone_remove(t_zone *zone);
void	_print_zones(void);

/*
** helpers
*/
char	_get_type(size_t size);
size_t	_aligned_size(size_t size);
char	*_endzone(t_zone *zone);
char	*_endalloc(t_alloc *alloc);
char	_is_space_middle_alloc(t_alloc *head, size_t size);
char	_is_space_end_alloc(t_alloc *head, t_zone *zone, size_t size);
char	_is_space_begin_zone(t_alloc *head, t_zone *zone, size_t size);
size_t	_count_zone_bytype(char type);
t_zone	*_find_zone(void *ptr);
void	_zone_sort(void);

/*
** constructor && destructor 
*/
void	_constructor(void) __attribute__((constructor (101)));
void	_destructor(void) __attribute__((destructor (101)));

#endif
