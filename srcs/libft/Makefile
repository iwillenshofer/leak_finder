# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 10:55:01 by iwillens          #+#    #+#              #
#    Updated: 2023/05/26 12:11:30 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#          a Limited version of libft specific for the malloc project          #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_putchar.c \
		ft_puthex.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_puthex_byte.c \
		ft_isprint.c \
		ft_strcpy.c \
		ft_memset.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
		@ar -r $(NAME) $(OBJS)
		@echo "\033[95m${NAME} is built. \033[0m"

%.o: %.c
		@gcc -c -Wall -Wextra -Werror -fvisibility=hidden $< -o $@ 

clean: 
		@rm -f $(OBJS)

fclean : clean
		@rm -f $(NAME)

re : fclean libft.a
