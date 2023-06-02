/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:08:09 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/02 15:30:32 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_realloc_up(void)
{
	char	*addr;
	char	*addr2;
	size_t	i;
	size_t	limit;

	i = 0;
	addr = NULL;
	addr2 = NULL;
	limit = (MEDIUM_LIMIT + (4096 * 2));
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
	}
}

void	test_realloc_down(void)
{
	char	*addr;
	char	*addr2;
	size_t	limit;

	addr = NULL;
	addr2 = NULL;
	limit = (MEDIUM_LIMIT + (4096 * 2));
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
	}
}

void test_realloc(void)
{
	test_realloc_up();
	test_realloc_down();
}
