/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 10:54:12 by iwillens          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/05/25 10:49:11 by iwillens         ###   ########.fr       */
=======
/*   Updated: 2023/05/25 08:54:40 by iwillens         ###   ########.fr       */
>>>>>>> 363fe2f379823f154b871749161254caae200b70
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>

# define BLACK 30
# define RED 31
# define GREEN 32
# define YELLOW 33
# define BLUE 34
# define PURPLE 35
# define CYAN 36
# define WHITE 37
# define RESET 0

# define REGULAR 0
# define BOLD 1
# define FAINT 2
# define ITALIC 3
# define UNDERLINE 4

# define TRUE 1
# define FALSE 0

void	ft_color(size_t color, size_t bold);
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
