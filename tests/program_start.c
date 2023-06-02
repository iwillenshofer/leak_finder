/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:53:58 by iwillens          #+#    #+#             */
/*   Updated: 2023/06/02 14:11:11 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void test_program_start(void)
{
	char *s[50];
	s[1] = (char *)malloc(1536);
	/*malloc result: 0x10f5c0050*/
	s[2] = realloc(0x0, 64) ;
	s[3] = (char *)malloc(64);
	/*malloc result: 0x110229050*/
	s[5] = (char *)malloc(32);
	/*malloc result: 0x1102290b0*/
	s[5] = (char *)malloc(32);
	/*malloc result: 0x1102290f0*/
	s[6] = realloc(0x0, 256);
	s[7] = (char *)malloc(256);
	/*malloc result: 0x110229130*/
	s[8] = realloc(s[7], 768);
	/* realloc result: 0x110229130*/
	/* s7 must be equal s8*/
	free(s[7]);
	s[9] = (char *)malloc(16);
	/*malloc result: 0x110229130*/
	s[10] = (char *)malloc(45);
	/*malloc result: 0x110229160*/
	s[11] = (char *)malloc(265);
	/*malloc result: 0x1102291b0*/
	s[12] = (char *)malloc(45);
	/*malloc result: 0x1102292e0*/
	s[13] = (char *)malloc(50);
	/*malloc result: 0x110229330*/
	s[14] = (char *)malloc(47);
	/*malloc result: 0x110229390*/
	s[15] = (char *)malloc(16);
	/*malloc result: 0x1102293e0*/
	s[16] = (char *)malloc(64);
	/*malloc result: 0x110229410*/
	s[17] = (char *)malloc(52);
	s[18] = (char *)malloc(54);
	/*malloc result: 0x1102294d0*/
	s[19] = (char *)malloc(12);
	/*malloc result: 0x110229530;*/
	s[20] = (char *)malloc(45);
	/*malloc result: 0x110229560;*/
	s[21] = (char *)malloc(102);
	/*malloc result: 0x1102295b0;*/
	free(0x0) ;
	s[22] = (char *)malloc(16);
	/*malloc result: 0x110229640;*/
	s[23] = (char *)malloc(64);
	/*malloc result: 0x110229670;*/
	s[24] = (char *)malloc(14);
	/*malloc result: 0x1102296d0;*/
	s[25] = (char *)realloc(s[1], 1);
	show_alloc_mem();
}
