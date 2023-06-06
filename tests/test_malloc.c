/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:53:26 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/06 09:54:16 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <sys/resource.h>

void	test_malloc(void)
{
	struct rlimit rlp;
	getrlimit(RLIMIT_MEMLOCK, &rlp);
	ft_putstr("TR SIZE:");
	ft_putnbr(rlp.rlim_cur);
	ft_putstr(" : ");
	ft_putnbr(rlp.rlim_max);
	ft_putstr("\n");
	char *s = malloc(rlp.rlim_max);
	ft_putstr("MALLOCED ");
	ft_puthex((size_t)s);
	ft_putstr("\n");
	
	free(s);
}