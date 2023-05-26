/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 10:54:12 by iwillens          #+#    #+#             */
/*   Updated: 2023/05/26 12:04:43 by iwillens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

void	ft_putchar(char c);
void	ft_puthex(size_t nb);
void	ft_putnbr(int nb);
void	ft_putstr(const char *s);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_puthexbyte(unsigned char c);
char	ft_isprint(char c);
char	*ft_strcpy(char *dst, char *src);
void	*ft_memset(void *b, int c, size_t len);

#endif
