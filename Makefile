NAME = pipex

SRCS = main.c \

CC = gcc -g3

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = obj

LIBFT_PATH = ./Libft

LIBFT_NAME = libft.a

INCLUDES = pipex.h

OBJS = ${addprefix ${OBJS_DIR}/, ${SRCS:.c=.o}}

${OBJS_DIR}/%.o: %.c ${INCLUDES}
	@mkdir -p ${dir $@}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${LIBFT_PATH}/${LIBFT_NAME}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${LIBFT_PATH} -lft

${LIBFT_PATH}/${LIBFT_NAME}:
	make -C ${LIBFT_PATH}

all: ${NAME}

clean:
	rm -r ${OBJS_DIR}
	make clean -C ${LIBFT_PATH}

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBFT_PATH}/${LIBFT_NAME}

re: fclean all

.PHONY: all clean fclean re

