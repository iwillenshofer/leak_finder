/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:53:26 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/06 14:46:34 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <sys/resource.h>

void	test_malloc(void)
{
	int i = 1000000;
	char *s;
	while (i > 0)
	{
		s = malloc(10);
		i--;
	}
}







