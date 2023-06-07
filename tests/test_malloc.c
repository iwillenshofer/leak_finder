/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:53:26 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/07 10:47:36 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <sys/resource.h>

void	test_malloc_size(size_t size)
{
	int		i;
	char	*s[MALLOC_TEST_SIZE];

	ft_putstr("Testing malloc(");
	ft_putnbr(size);
	ft_putstr(") ");
	ft_putnbr(MALLOC_TEST_SIZE);
	ft_putstr(" times.\n");
	i = MALLOC_TEST_SIZE;
	while (i > 0)
		s[--i] = malloc(size);
	while (i < MALLOC_TEST_SIZE)
		free(s[i++]);
}

void	test_malloc(void)
{
	test_malloc_size(0);
	test_malloc_size(TINY_LIMIT);
	test_malloc_size(SMALL_LIMIT);
	test_malloc_size(SMALL_LIMIT + 1);
}
