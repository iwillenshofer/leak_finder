/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:52:02 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 17:41:58 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

t_zone			*g_zones = NULL;
t_info			g_record[RECORD_BUFFER] = {0};
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

t_info	_info(const char *file, const char *function, int line)
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
	ft_putstr("SHOWING LEAKS:\n");
	while (i < RECORD_BUFFER)
	{
		if (g_record[i].address)
		{
			ft_puthex((size_t)g_record[i].address);
			ft_putstr(" ");
			ft_putnbr(g_record[i].size);
			ft_putstr(" bytes. Allocated on ");
			if (g_record[i].function)
				ft_putstr(g_record[i].function);
			ft_putstr(" ");
			if (g_record[i].file)
				ft_putstr(g_record[i].file);
			ft_putstr(" : ");
			ft_putnbr(g_record[i].line);
			ft_putstr("\n");
			leaks++;
		}
		i++;
	}
	if (!leaks)
		ft_putstr("NO LEAKS FOUND\n");
}

void	_record(int action, t_info info)
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
			ft_bzero(&(g_record[i]), sizeof(t_info));
			return ;
		}
		i++;
	}
}

void	_free(void *ptr, t_info info)
{
	(void)info;
	if (ptr)
	{
		lock_mutex();
		_alloc_remove(ptr);
		unlock_mutex();
		info.address = ptr;
		_record(ACTION_REMOVE, info);
	}
	return ;
}

void	*_malloc(size_t size, t_info info)
{
	t_alloc	*new_alloc;

	(void)info;
	if (!(size))
		return (NULL);
	lock_mutex();
	new_alloc = _alloc_add(size);
	unlock_mutex();
	if (!(new_alloc))
		return (NULL);
	info.address = new_alloc->ptr;
	info.size = size;
	_record(ACTION_ADD, info);
	return (new_alloc->ptr);
}

void	*_realloc(void *ptr, size_t size, t_info info)
{
	t_alloc	*new_alloc;

	(void)info;
	if (!ptr)
		return (_malloc(size, info));
	if (!(size))
	{
		_free(ptr, info);
		return (NULL);
	}
	lock_mutex();
	new_alloc = _alloc_realloc(ptr, size);
	unlock_mutex();
	if (!(new_alloc))
		return (NULL);
	info.address = new_alloc->ptr;
	info.size = size;
	_record(ACTION_ADD, info);
	return (new_alloc->ptr);
}

void	*_calloc(size_t count, size_t size, t_info info)
{
	void	*s;

	(void)info;
	s = _malloc(count * size, info);
	if (!(s))
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}

void	show_alloc_mem(void)
{
	lock_mutex();
	_print_zones();
	unlock_mutex();
}

void	show_alloc_mem_ex(void)
{
	lock_mutex();
	_print_zones_ex();
	unlock_mutex();
}
