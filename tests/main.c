/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:15:00 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/06 14:28:33 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

#define THREADS 100
# define SENTENCE "Long text for a thread to see if it crashes\n"


int main (void)
{
	test_malloc();
	test_realloc();
	return (0);
}
/*
void* thread_function(void *arg)
{
	(void)arg;
	ft_putstr(SENTENCE);
	return (NULL);
}

int main3 (void)
{
	int i = 0;
	pthread_t tid[THREADS];
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













int main4 (void)
{
	char *alloc;
	char *alloc2;
	(void)alloc2;
	int i = 0;
	int z = 0;
	while (i++ < 1000)
	{
		alloc = malloc(TINY_LIMIT);
		z = 0;
		while (z < TINY_LIMIT)
			alloc[z++] = '-';
		alloc[TINY_LIMIT - 1]='X';
	}
	alloc = malloc(1);
	alloc = malloc(1);
	alloc = malloc(1);
	alloc = malloc(85-32);
	/	
*alloc = '0';
	alloc2 = malloc(18);
	*alloc2 = '0';
	alloc = realloc(alloc, 16 * 2);
	alloc = malloc(16*2);
	show_alloc_mem_ex();
	free(alloc);
	return (0);
}


void* thread_function3(void *arg)
{
	char *s;

	s = malloc(ft_strlen(SENTENCE) + 1);
	show_alloc_mem();
	ft_putstr(SENTENCE);
	ft_strcpy(s, SENTENCE);
	ft_putstr(s);
	free(s);
	(void)(arg);
	return NULL;
}

int main2(void)
{
	int i = 0; 

	pthread_t tid[THREADS];
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
*/