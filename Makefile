# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <iwillens@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/23 17:38:02 by iwillens          #+#    #+#              #
#    Updated: 2023/05/22 10:51:02 by iwillens         ###   ########.fr        #
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
CCFLAGS = -Wall -Werror -Wextra -std=c89 -fvisibility=hidden -DDEBUG=1# -fsanitize=address -g

SRC_DIR = ./srcs
OBJ_DIR = ./build
INC_DIR = ./includes
INCLUDES = ${INC_DIR}/libft_malloc.h

SRCS = ${SRC_DIR}/malloc.c \
		${SRC_DIR}/zone_add.c \
		${SRC_DIR}/zone_remove.c \
		${SRC_DIR}/zone_sort.c \
		${SRC_DIR}/alloc_add.c \
		${SRC_DIR}/alloc_add_helpers.c \
		${SRC_DIR}/alloc_remove.c \
		${SRC_DIR}/alloc_realloc.c \
		${SRC_DIR}/alloc_realloc_helpers.c \
		${SRC_DIR}/print.c \
		${SRC_DIR}/constructor.c \
		${SRC_DIR}/alignment.c \
		${SRC_DIR}/thread_safe.c


OBJS = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS})
DEPENDS = $(patsubst %.o, %.d, ${OBJS})

# **************************************************************************** #
# *** Libft Definitions                                                        #
# **************************************************************************** #
LIBFT_DIR = ./srcs/libft
LIBFT = ${LIBFT_DIR}/libft.a

# **************************************************************************** #
# *** Tester Definitions                                                       #
# **************************************************************************** #
TEST = tester
TESTS_SRC_DIR = ./tests
TESTS_OBJ_DIR = ./tests/build
TESTS_INCLUDES = ${TESTS_SRC_DIR}/tests.h

TESTS = ${TESTS_SRC_DIR}/main.c \
		${TESTS_SRC_DIR}/print_zone.c 
#		${TESTS_SRC_DIR}/test_alloc.c \
#		${TESTS_SRC_DIR}/test_realloc.c \
#		${TESTS_SRC_DIR}/test_free.c
#
TESTS_OBJS = $(patsubst ${TESTS_SRC_DIR}/%.c, ${TESTS_OBJ_DIR}/%.o, ${TESTS})

# **************************************************************************** #
# *** Main Rules                                                               #
# **************************************************************************** #

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS} ${INCLUDES} Makefile
	@gcc ${CCFLAGS} ${OBJS}  -L./srcs/libft -lft -shared -o ${NAME}
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
# *** Test Rules                                                               #
# **************************************************************************** #

${TEST}: ${NAME} ${TESTS_OBJS} ${INCLUDES} ${TESTS_INCLUDES} Makefile
	@${CC} ${CCFLAGS}  ${TESTS_OBJS} -I. -I ${INC_DIR} -I ${TESTS_SRC_DIR} -I ${LIBFT_DIR} -L./ -lft_malloc -L${LIBFT_DIR} -lft -o ${TEST}
	@echo "\033[92m${TEST} is built. \033[0m"
	

${TESTS_OBJ_DIR}/%.o: ${TESTS_SRC_DIR}/%.c ${INC_DIR} ${INCLUDES} ${TESTS_INCLUDES} Makefile
	@mkdir -p $(dir $@)
	@${CC}  ${CCFLAGS} -MMD -c $< -I. -I ${INC_DIR} -I ${TESTS_SRC_DIR} -I ${LIBFT_DIR} -o $@

test: ${NAME} ${TEST}
	./${TEST}

time: test
	time -l ./${TEST}

# **************************************************************************** #
# *** Common Rules                                                             #
# **************************************************************************** #
clean:
	@rm -rf ${OBJ_DIR}
	@make -C ${LIBFT_DIR} clean

fclean: clean
	@rm -rf ./${NAME} ./${SYMLINK}
	@rm -rf ./${TESTS_OBJ_DIR} ./${TEST}
	@make -C ${LIBFT_DIR} fclean

re: fclean all

-include $(DEPENDS)
