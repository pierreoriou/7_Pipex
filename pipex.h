/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:04:11 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/10 19:49:14 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_cmd
{
	char			**content;
	struct s_cmd	*next;
}					t_cmd;


typedef struct s_args
{
	char	*file1;
	char	*file2;
	t_cmd	*cmd;
}			t_args;

int		main(int argc, char *argv[], char *envp[]);
void	init_args(t_args *args, int argc, char *argv[]);
pid_t	initiate_fork(void);
void	initiate_waitpid(pid_t pid, int *wstatus);
void	initiate_pipe(int pipefd[2]);
/* CHILD */
int		exec_cpid1(char *argv[], char *envp[], int pipefd[]);
int		exec_cpid2(char *argv[], char *envp[], int pipefd[]);
void	access_child1_file(char *arg);
void	exec_child1_cmd(char *cmd, char *envp[], int pipefd[]);
void	exec_child2_cmd(int outfile_fd, char *cmd, char *envp[], int pipefd[]);
/* GETTERS */
char	*get_envp_path(char *envp[]);
char	*get_cmd_path(char *cmd, char *path);
/* PRINTS */
void	print_argv(char **arguments);
void	print_commands(t_cmd *cmd);
void	print_args(t_args *args);
void	print_cpid_status(int wstatus);
/* FREE */
void	free_args(t_args *args);

#endif

// void	check_file1_permissions(char *file);
// void	check_folder_permissions(char *file);
// void	check_command_isempty(char *cmd);
// void	check_command_isspace(char *cmd);
// void	check_filename_isempty(char *file);
// void	check_filename_isspace(char *file);
// void	check_filename_characters(char *file, int n);
// char	*trim_arg(char *arg);
// void	check_filename_len(char *file);
// void	check_file1_exists(char *file);
// void	check_file1_isdir(char *file);
// void	check_command_executability(t_args *args, char *cmd, char *envp[]);
