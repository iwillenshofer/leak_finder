# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 10:55:01 by iwillens          #+#    #+#              #
#    Updated: 2023/05/12 12:45:36 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#          a Limited version of libft specific for the malloc project          #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_color.c \
			ft_putchar.c \
			ft_puthex.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strlen.c \
			ft_bzero.c \
			ft_memcpy.c

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
