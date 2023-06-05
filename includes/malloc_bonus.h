/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:29:28 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/05 18:12:11 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_BONUS_H
# define MALLOC_BONUS_H

# include <pthread.h>
# include "malloc_internal.h"

/*
** Mutex global variable
*/
pthread_mutex_t	g_mutex;

/*
** definitions for show_mem_ex
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

# define PRINT_COLUMNS 64

typedef struct s_color
{
	char	color;
	char	options;
}	t_color;

/*
** mandatory function
*/

void	show_alloc_mem_ex(void)
		__attribute__ ((visibility ("default")));

/*
** show_mem_hex
*/
void	_put_color(char new_color, char new_opt, t_color *current);
void	_print_buffer(char *s, t_color *color);
void	_clear_buffer(char *s);
void	_print_addr_type_color(t_zone *zone, char *addr,
			t_alloc *next_alloc, t_color *color);
void	_print_zone_information(t_zone *zone);
void	_print_zones_ex(void);

/*
** mutex functions
*/
void	lock_mutex(void);
void	unlock_mutex(void);

#endif
