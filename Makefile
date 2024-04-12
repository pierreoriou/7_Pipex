NAME = pipex

SRCS =	main2.c \
		initiate_fork.c \
		initiate_waitpid.c \
		initiate_pipe.c \
		init/init_args.c \
		init/init_dup2.c \
		exec_cpid1.c \
		exec_cpid2.c \
		free_args.c \
		free_exit_cpid.c \
		close_both_fd.c \
		getters/get_envp_path.c \
		getters/get_cmd1_path.c \
		getters/get_cmd2_path.c \
		print/print_argv.c \
		print/print_commands.c \
		print/print_args.c \
		print/print_cpid_status.c \

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = obj

LIBFT_PATH = ./Libft

TEST_PATH = ./Tester

TEST_NAME = tester

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
	rm -rf ${OBJS_DIR}
	make clean -C ${LIBFT_PATH}

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBFT_PATH}/${LIBFT_NAME}

re: fclean all

.PHONY: all clean fclean re

