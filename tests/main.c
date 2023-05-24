/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:15:00 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/22 10:59:06 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libft_malloc.h"
#define THREADS 100

# define SENTENCE "Long text for a thread to see if it crashes\n"

void	ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = *src;
}

int main (void)
{
	char *alloc;
	char *alloc2;
	(void)alloc2;
	int i = 0;
	while (i++ < 1000)
	{
		alloc = malloc(513);
		ft_strcpy(alloc, "hello");
	}
/*	
*alloc = '0';
	alloc2 = malloc(18);
	*alloc2 = '0';
	alloc = realloc(alloc, 16 * 2);
	alloc = malloc(16*2);*/
	show_alloc_mem_ex();
	free(alloc);
	return (0);
}


void* thread_function(void *arg)
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
