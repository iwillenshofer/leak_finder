/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_safe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:51:51 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/21 17:03:07 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

void	create_mutex(void)
{
	pthread_mutex_init(&g_mutex, NULL);
}

void	destroy_mutex(void)
{
	pthread_mutex_destroy(&g_mutex);
}

void	lock_mutex(void)
{
	pthread_mutex_lock(&g_mutex);
}

void	unlock_mutex(void)
{
	pthread_mutex_unlock(&g_mutex);
}
