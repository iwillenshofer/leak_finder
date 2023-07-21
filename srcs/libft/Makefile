# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 10:55:01 by iwillens          #+#    #+#              #
#    Updated: 2023/07/21 18:56:03 by igorwillens      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#          a Limited version of libft specific for the malloc project          #
# **************************************************************************** #

NAME = libft.a

SRCS =  ftm_putchar.c \
		ftm_puthex.c \
		ftm_putnbr.c \
		ftm_putstr.c \
		ftm_strlen.c \
		ftm_bzero.c \
		ftm_memcpy.c \
		ftm_puthex_byte.c \
		ftm_isprint.c \
		ftm_strcpy.c \
		ftm_memset.c

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
