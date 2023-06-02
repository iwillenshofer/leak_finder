/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:21:07 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/02 14:28:12 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <pthread.h>
# include "../srcs/libft/libft.h"

# define TINY 0
# define MEDIUM 1
# define LARGE 2

# define TINY_LIMIT 256
# define MEDIUM_LIMIT 1024

# define ALIGNMENT 16
# define PROTECTED 0

# define DEBUG 1

# define TRUE 1
# define FALSE 0

# define PRINT_COLUMNS 64

/*
** color definitions for show_mem_ex
*/
# define BLACK 30
# define RED 31
# define GREEN 32
# define YELLOW 33
# define BLUE 34
# define PURPLE 35
# define CYAN 36
# define WHITE 37
# define RESET 0

# define REGULAR 0
# define BOLD 1
# define FAINT 2
# define ITALIC 3
# define UNDERLINE 4

typedef struct s_color
{
    char color;
    char options;
}   t_color;

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
	char			protect[PROTECTED];
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
** next: this one is obvious
** prev: also obvious, not really needed, but makes sorting easier
*/

typedef struct s_zone
{
	char			protect[PROTECTED];		
	t_alloc			*allocs;
	size_t			size;
	char			type;
	struct s_zone	*prev;
	struct s_zone	*next;
}	t_zone;

/*
** global variables for zones (allocations) and thread safe.
*/
t_zone			*g_zones;
pthread_mutex_t	g_mutex;

void	free(void *ptr)
		__attribute__ ((visibility ("default")));

void	*malloc(size_t size)
		__attribute__ ((visibility ("default")));

void	*realloc(void *ptr, size_t size)
		__attribute__ ((visibility ("default")));

void	show_alloc_mem(void)
		__attribute__ ((visibility ("default")));

void	show_alloc_mem_ex(void)
		__attribute__ ((visibility ("default")));

t_zone	*zone_add(char type, size_t size);
void	zone_remove(t_zone *zone);
void	zone_sort(void);
t_alloc	*alloc_add(size_t size);
void	alloc_remove(void *ptr);
t_alloc	*alloc_realloc(void *ptr, size_t size);
void	_print_zones(void);
void	_print_zones_ex(void);

void	create_mutex(void);
void	destroy_mutex(void);
void	lock_mutex(void);
void	unlock_mutex(void);

/*
** helpers
*/
char	get_type(size_t size);
size_t	_aligned_size(size_t size);
char	*_endzone(t_zone *zone);
char	*_endalloc(t_alloc *alloc);
char	_is_space_middle_alloc(t_alloc *head, size_t size);
char	_is_space_end_alloc(t_alloc *head, t_zone *zone, size_t size);
char	_is_space_begin_zone(t_alloc *head, t_zone *zone, size_t size);
char	_is_space_realloc_middle(t_alloc *alloc, size_t size);
char	_is_space_realloc_end(t_alloc *alloc, t_zone *zone, size_t size);

/*
** show_mem_hex
*/
void	_put_color(char new_color, char new_opt, t_color *current);
void	_print_buffer(char *s, t_color *color);
void	_clear_buffer(char *s);
void	_print_addr_type_color(t_zone *zone, char *addr,
	t_alloc *next_alloc, t_color *color);
void	_print_zone_information(t_zone *zone);

/*
** constructor && destructor 
*/
void	_constructor(void) __attribute__((constructor (101)));
void	_destructor(void) __attribute__((destructor (101)));

#endif
