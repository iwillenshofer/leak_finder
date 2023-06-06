/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:15:00 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/06 21:19:22 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	*thread_function(void *arg)
{
	test_malloc();
	test_realloc();
	show_alloc_mem();
	return (NULL);
}

int	main(void)
{
	int			i;
	pthread_t	tid[THREADS];

	i = 0;
	while (i < THREADS)
	{
		pthread_create(&(tid[i]), NULL, &thread_function, NULL);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (0);
}
