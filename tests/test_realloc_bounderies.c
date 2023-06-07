/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_realloc_bounderies.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:34:27 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/07 10:47:36 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/*
** reallocates a memory address to the size of itself + 1
** should, in principle, only reallocate to a different address on the
** bonderies of the zone (if nothing has been previously allocated)
*/
void	test_realloc_up(void)
{
	char	*addr;
	char	*addr2;
	size_t	i;
	size_t	limit;

	i = 0;
	addr = NULL;
	addr2 = NULL;
	limit = (SMALL_LIMIT + (4096 * 2));
	ft_putstr("*** TESTING REALLOC UP \n");
	while (i < limit)
	{
		addr = malloc(i);
		addr2 = realloc(addr, ++i);
		if (addr != addr2)
		{
			ft_putstr("new address when reallocating ");
			ft_putnbr(i - 1);
			ft_putstr(" to ");
			ft_putnbr(i);
			ft_putstr(".\n");
		}
		free(addr2);
	}
}

/*
** same as above, but starting which large alloc and reallocating to one less
** until zero.
*/
void	test_realloc_down(void)
{
	char	*addr;
	char	*addr2;
	size_t	limit;

	addr = NULL;
	addr2 = NULL;
	limit = (SMALL_LIMIT + (4096 * 2));
	ft_putstr("*** TESTING REALLOC DOWN \n");
	while (limit)
	{
		addr = malloc(limit);
		addr2 = realloc(addr, --limit);
		if (addr != addr2)
		{
			ft_putstr("new address when reallocating ");
			ft_putnbr(limit + 1);
			ft_putstr(" to ");
			ft_putnbr(limit);
			ft_putstr(".\n");
		}
		free(addr2);
	}
}

void	test_realloc_bounderies(void)
{
	test_realloc_down();
	test_realloc_up();
}
