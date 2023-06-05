/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_safe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:51:51 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/05 17:19:31 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_bonus.h"

void	lock_mutex(void)
{
	pthread_mutex_lock(&g_mutex);
}

void	unlock_mutex(void)
{
	pthread_mutex_unlock(&g_mutex);
}
