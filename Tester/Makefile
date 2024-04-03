NAME = tester

SRCS = main.c \

OBJS_DIR = tester_objs

LIB_PATH = ./Libft_copy

LIB_NAME = libft_copy.a

PIPEX_PATH = ..

PIPEX_NAME = pipex

INCLUDES = tester.h

CC = gcc -g3

CFLAGS = -Wall -Wextra -Werror

OBJS = ${addprefix ${OBJS_DIR}/, ${SRCS:.c=.o}}

${OBJS_DIR}/%.o: %.c ${INCLUDES}
	@mkdir -p ${dir $@}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${LIB_PATH}/${LIB_NAME} ${PIPEX_PATH}/${PIPEX_NAME}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${LIB_PATH} -lft_copy

all: ${NAME}

${LIB_PATH}/${LIB_NAME}:
	make -C ${LIB_PATH}

${PIPEX_PATH}/${PIPEX_NAME}:
	make -C ${PIPEX_PATH}

clean:
	rm -rf ${OBJS_DIR}
	make clean -C ${LIB_PATH}

fclean: clean
	rm -f ${NAME}
	rm -f ${LIB_PATH}/${LIB_NAME}

re: fclean all

run: ${NAME}
	./${NAME}

.PHONY: all clean fclean re run
