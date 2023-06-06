/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:08:09 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/06 21:21:48 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/*
** tests reallocating an address if there is already a free space between
** alloc and next allocation.
*/
void	test_realloc_middle(void)
{
	char	*addr[4];

	addr[0] = (char *)malloc(100);
	addr[1] = (char *)malloc(100);
	addr[2] = (char *)malloc(100);
	free(addr[1]);
	addr[3] = (char *)realloc(addr[0], 256);
	if (addr[0] == addr[3])
		ft_putstr("Reallocated on the same address\n");
	else
		ft_putstr("Reallocated on different addresses\n");
	free(addr[0]);
	free(addr[2]);
}

/*
** tests reallocating a previously allocated pointer of size (lower_limit)
** into a larger size (upper_limit). should allocate on the same address if
** both sizes are within the zone's limit range.
*/
void	test_realloc_limit(size_t lower_limit, size_t upper_limit)
{
	char	*addr;
	char	*addr2;

	addr = (char *)malloc(lower_limit);
	addr2 = (char *)realloc(addr, upper_limit);
	if (addr == addr2)
		ft_putstr("Reallocated on the same address\n");
	else
		ft_putstr("Reallocated on different addresses\n");
	free(addr2);
}

void	test_realloc_to_tiny(void)
{
	char	*s[3];

	s[0] = malloc(MEDIUM_LIMIT + 1);
	s[0][0] = 'a';
	s[1] = realloc(s[0], 1);
	if (s[0] != s[1] && s[1][0] == 'a')
		ft_putstr("Reallocating down worked\n");
	else
		ft_putstr("Reallocated down failed\n");
	s[2] = realloc(s[1], TINY_LIMIT + 1);
	if (s[2] != s[1] && s[2][0] == 'a')
		ft_putstr("Reallocating up worked\n");
	else
		ft_putstr("Reallocated up failed\n");
	free(s[2]);
}

void	test_realloc(void)
{
	test_realloc_bounderies();
	test_realloc_limit(1, TINY_LIMIT);
	test_realloc_limit(TINY_LIMIT + 1, MEDIUM_LIMIT);
	test_realloc_limit(1, TINY_LIMIT + 1);
	test_realloc_limit(TINY_LIMIT + 1, MEDIUM_LIMIT + 1);
	test_realloc_middle();
	test_realloc_to_tiny();
}
