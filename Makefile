NAME = pipex

SRCS =	main.c \
		initiate_fork.c \
		initiate_waitpid.c \
		initiate_pipe.c \
		init/init_args.c \
		exec_cpid1.c \
		exec_cpid2.c \
		free_args.c \
		getters/get_envp_path.c \
		getters/get_cmd_path.c \
		print/print_argv.c \
		print/print_commands.c \
		print/print_args.c \
		print/print_cpid_status.c \
		# parsing/check_file1_permissions.c \
		# parsing/check_folder_permissions.c \
		# parsing/check_command_executability.c \
		# parsing/check_command_isempty.c \
		# parsing/check_command_isspace.c \
		# parsing/check_filename_isempty.c \
		# parsing/check_filename_isspace.c \
		# parsing/check_filename_characters.c \
		# parsing/trim_arg.c \
		# parsing/check_filename_len.c \
		# parsing/check_file1_exists.c \
		# parsing/check_file1_isdir.c \

CC = gcc -g3

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

test: all
	cp ${NAME} ${TEST_PATH}
	make run -C ${TEST_PATH}

clean:
	rm -rf ${OBJS_DIR}
	make clean -C ${LIBFT_PATH}
	make clean -C ${TEST_PATH}

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBFT_PATH}/${LIBFT_NAME}
	rm -f ${TEST_NAME}
	rm -f ${TEST_PATH}/${TEST_NAME}

re: fclean all

retest: fclean test

.PHONY: all clean fclean re test retest

