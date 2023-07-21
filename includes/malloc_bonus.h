/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:29:28 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 19:45:25 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_BONUS_H
# define MALLOC_BONUS_H

# include <pthread.h>
# include "malloc_internal.h"

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef false

typedef enum e_bool {false, true}	t_bool;

# else

typedef char	t_bool;

# endif
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
# define ITALIC 3

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
void	m_put_color(char new_color, char new_opt, t_color *current);
void	m_print_buffer(char *s, t_color *color);
void	m_clear_buffer(char *s);
t_bool	m_print_addr_type_color(t_zone *zone, char *addr,
			t_alloc *next_alloc, t_color *color);
void	m_print_zone_information(t_zone *zone);
void	m_print_zones_ex(void);

/*
** mutex functions
*/
void	lock_mutex(void);
void	unlock_mutex(void);

#endif
