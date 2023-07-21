/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:52:02 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 19:47:54 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

t_zone			*g_zones = NULL;
t_info			g_record[RECORD_BUFFER] = {0};
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

t_info	info(const char *file, const char *function, int line)
{
	t_info info;

	info.size = 0;
	info.address = 0;
	info.file = file;
	info.function = function;
	info.line = line;
	return (info);
}
void	print_leaks(void)
{
	size_t i;
	size_t leaks;

	i = 0;
	leaks = 0;
	m_put_color(WHITE, BOLD, NULL);
	ftm_putstr("\nSEARCHING LEAKS:\n");
	while (i < RECORD_BUFFER)
	{
		if (g_record[i].address)
		{
			m_put_color(CYAN, REGULAR, NULL);
			ftm_puthex((size_t)g_record[i].address);
			ftm_putstr(" ");
			m_put_color(BLUE, REGULAR, NULL);
			ftm_putnbr(g_record[i].size);
			ftm_putstr(" bytes");
			m_put_color(WHITE, FAINT, NULL);
			ftm_putstr(", allocated on ");
			m_put_color(WHITE, ITALIC, NULL);
			if (g_record[i].function)
				ftm_putstr(g_record[i].function);
			ftm_putstr("() ");
			m_put_color(PURPLE, BOLD, NULL);
			if (g_record[i].file)
				ftm_putstr(g_record[i].file);
			ftm_putstr(" : ");
			ftm_putnbr(g_record[i].line);
			ftm_putstr("\n");
			leaks++;
			m_put_color(RESET, REGULAR, NULL);
		}
		i++;
	}
	if (!leaks)
	{
		m_put_color(GREEN, BOLD, NULL);
		ftm_putstr("NO LEAKS FOUND\n\n");
	}
	else
	{
		m_put_color(RED, BOLD, NULL);
		ftm_putstr("FOUND ");
		ftm_putnbr(leaks);
		ftm_putstr(" LEAKS\n\n");
	}
	m_put_color(RESET, REGULAR, NULL);
}

void	m_record(int action, t_info info)
{
	size_t i;

	i = 0;
	while (i < RECORD_BUFFER)
	{
		if ((action == ACTION_ADD) && (g_record[i].address == 0))
		{
			g_record[i] = info;
			return ;
		}
		else if (action == ACTION_REMOVE && g_record[i].address == info.address)
		{
			ftm_bzero(&(g_record[i]), sizeof(t_info));
			return ;
		}
		i++;
	}
}

void	m_free(void *ptr, t_info info)
{
	(void)info;
	if (ptr)
	{
		lock_mutex();
		m_alloc_remove(ptr);
		unlock_mutex();
		info.address = ptr;
		m_record(ACTION_REMOVE, info);
	}
	return ;
}

void	*m_malloc(size_t size, t_info info)
{
	t_alloc	*new_alloc;

	(void)info;
	if (!(size))
		return (NULL);
	lock_mutex();
	new_alloc = m_alloc_add(size);
	unlock_mutex();
	if (!(new_alloc))
		return (NULL);
	info.address = new_alloc->ptr;
	info.size = size;
	m_record(ACTION_ADD, info);
	return (new_alloc->ptr);
}

void	*m_realloc(void *ptr, size_t size, t_info info)
{
	t_alloc	*new_alloc;

	(void)info;
	if (!ptr)
		return (m_malloc(size, info));
	if (!(size))
	{
		m_free(ptr, info);
		return (NULL);
	}
	lock_mutex();
	new_alloc = m_alloc_realloc(ptr, size);
	unlock_mutex();
	if (!(new_alloc))
		return (NULL);
	info.address = new_alloc->ptr;
	info.size = size;
	m_record(ACTION_ADD, info);
	return (new_alloc->ptr);
}

void	*m_calloc(size_t count, size_t size, t_info info)
{
	void	*s;

	(void)info;
	s = m_malloc(count * size, info);
	if (!(s))
		return (NULL);
	ftm_bzero(s, count * size);
	return (s);
}

void	show_alloc_mem(void)
{
	lock_mutex();
	m_print_zones();
	unlock_mutex();
}

void	show_alloc_mem_ex(void)
{
	lock_mutex();
	m_print_zones_ex();
	unlock_mutex();
}
