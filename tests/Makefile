# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 20:47:21 by iwillens          #+#    #+#              #
#    Updated: 2023/06/06 21:20:09 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *** Config

MALLOC_DIR=../
INC_DIR=${MALLOC_DIR}/includes/

# **************************************************************************** #
# *** Tester Definitions                                                       #
# **************************************************************************** #
CC = gcc
TEST = tester
TESTS_SRC_DIR = ./
TESTS_OBJ_DIR = ./build

TESTS = ${TESTS_SRC_DIR}/libft.c \
		${TESTS_SRC_DIR}/main.c \
		${TESTS_SRC_DIR}/test_realloc.c \
		${TESTS_SRC_DIR}/test_realloc_bounderies.c \
		${TESTS_SRC_DIR}/test_malloc.c

TESTS_OBJS = $(patsubst ${TESTS_SRC_DIR}/%.c, ${TESTS_OBJ_DIR}/%.o, ${TESTS})

INCLUDES = tests.h

# **************************************************************************** #
# *** Test Rules                                                               #
# **************************************************************************** #

all: ${TEST}

${TEST}: ${MALLOC_DIR}/libft_malloc.so ${TESTS_OBJS} ${INCLUDES} Makefile
	@${CC} ${CCFLAGS}  ${TESTS_OBJS} -I. -I ${INC_DIR} -I ${TESTS_SRC_DIR} -L${MALLOC_DIR} -lft_malloc -o ${TEST}
	@echo "\033[92m${TEST} is built. \033[0m"

${TESTS_OBJ_DIR}/%.o: ${TESTS_SRC_DIR}/%.c ${INC_DIR} ${INCLUDES} Makefile
	@mkdir -p $(dir $@)
	@${CC}  ${CCFLAGS} -MMD -c $< -I. -I ${INC_DIR} -I ${TESTS_SRC_DIR}  -o $@

${MALLOC_DIR}/libft_malloc.so:
	make -C ${MALLOC_DIR}
	cp  ${MALLOC_DIR}libft_malloc.so .
	cp ${MALLOC_DIR}libft_malloc_x86_64_Darwin.so .

test: ${NAME} ${TEST}
	./${TEST}

# **************************************************************************** #
# *** Common Rules                                                             #
# **************************************************************************** #
clean:
	@rm -rf ${OBJ_DIR}
	@make -C ${MALLOC_DIR} clean

fclean: clean
	@rm -rf ./${TESTS_OBJ_DIR} ./${TEST}
	@make -C ${MALLOC_DIR} fclean

re: fclean all

-include $(DEPENDS)
