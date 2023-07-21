/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 10:54:12 by iwillens          #+#    #+#             */
/*   Updated: 2023/07/21 18:25:25 by igorwillens      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

# include <string.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

void	ftm_putchar(char c);
void	ftm_puthex(size_t nb);
void	ftm_putnbr(int nb);
void	ftm_putstr(const char *s);
size_t	ftm_strlen(const char *s);
void	ftm_bzero(void *s, size_t n);
void	*ftm_memcpy(void *dst, const void *src, size_t n);
void	ftm_puthexbyte(unsigned char c);
int		ftm_isprint(int c);
char	*ftm_strcpy(char *dst, char *src);
void	*ftm_memset(void *b, int c, size_t len);

#endif
