# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igorwillenshofer <igorwillenshofer@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 17:38:02 by iwillens          #+#    #+#              #
#    Updated: 2023/07/21 13:36:44 by igorwillens      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# *** Main Definitions                                                         #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_${HOSTTYPE}.so
SYMLINK = libft_malloc.so

CC = gcc
CCFLAGS = -Wall -Werror -Wextra -std=c89 -fvisibility=hidden -fsanitize=address -g -DDEBUG=1

SRC_DIR = ./srcs
COMMON_DIR = ${SRC_DIR}/common
BONUS_DIR = ${SRC_DIR}/bonus

OBJ_DIR = ./build

INC_DIR = ./includes

INCLUDES = ${INC_DIR}/malloc.h \
			${INC_DIR}/malloc_internal.h \
			${INC_DIR}/malloc_bonus.h

COMMON_SRCS = ${COMMON_DIR}/zone_add.c \
				${COMMON_DIR}/zone_remove.c \
				${COMMON_DIR}/zone_utils.c \
				${COMMON_DIR}/alloc_add.c \
				${COMMON_DIR}/alloc_add_helpers.c \
				${COMMON_DIR}/alloc_remove.c \
				${COMMON_DIR}/alloc_realloc.c \
				${COMMON_DIR}/show_mem.c \
				${COMMON_DIR}/constructor.c

BONUS_SRCS = ${BONUS_DIR}/show_mem_ex.c \
				${BONUS_DIR}/show_mem_colors.c \
				${BONUS_DIR}/show_mem_buffer.c \
				${BONUS_DIR}/show_mem_info.c \
				${BONUS_DIR}/thread_safe.c \
				${BONUS_DIR}/calloc.c

SRCS = ${COMMON_SRCS} ${BONUS_SRCS} ${SRC_DIR}/malloc.c

OBJS = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS})

DEPENDS = $(patsubst %.o, %.d, ${OBJS})

# **************************************************************************** #
# *** Libft Definitions                                                        #
# **************************************************************************** #
LIBFT_DIR = ./srcs/libft
LIBFT = ${LIBFT_DIR}/libft.a

# **************************************************************************** #
# *** Main Rules                                                               #
# **************************************************************************** #

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS} ${INCLUDES} Makefile
	@gcc ${CCFLAGS} ${OBJS}  -L./srcs/libft -lft -shared -o ${NAME}
#	@strip -x ${NAME}
	@rm -f ${SYMLINK}
	@ln -s ${NAME} ${SYMLINK}
	@echo "\033[96m${NAME} is built. \033[0m"
	
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${INC_DIR} ${INCLUDES} Makefile
	@mkdir -p $(dir $@)
	@${CC} ${CCFLAGS} -MMD -c $< -I. -I ${INC_DIR} -o $@ ${LDFLAGS}


# **************************************************************************** #
# *** Libft Rules                                                              #
# **************************************************************************** #

${LIBFT}:
	@make -C ${LIBFT_DIR}

# **************************************************************************** #
# *** Common Rules                                                             #
# **************************************************************************** #
clean:
	@rm -rf ${OBJ_DIR}
	@make -C ${LIBFT_DIR} clean

fclean: clean
	@rm -rf ./${NAME} ./${SYMLINK}
	@make -C ${LIBFT_DIR} fclean

re: fclean all

-include $(DEPENDS)
