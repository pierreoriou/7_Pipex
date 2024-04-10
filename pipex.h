/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:04:11 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/10 08:38:26 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <sys/wait.h>
# include <sys/types.h>


typedef struct s_args
{
	char	*file1;
	char	*file2;
	char	*cmd_path_1;
	char	*cmd_path_2;
	bool	file1_ok;
	bool	file2_ok;
	bool	cmd1_ok;
	bool	cmd2_ok;
}			t_args;

int		main(int argc, char *argv[], char *envp[]);
void	init_args(t_args *args);
/* CHILD */
int		exec_cpid(t_args *args, char *argv[], char *envp[]);
void	access_child_file(t_args *args, char *arg);
void	exec_child_command(t_args *args, char *arg, char *envp[]);
/* GETTERS */
char	*get_envp_path(char *envp[]);
char	*get_cmd_path(char *cmd, char *path);
/* PARENT */
void	check_command_executability(t_args *args, char *cmd, char *envp[]);
/* PRINTS */
void	print_args(char **arguments);
void	print_cpid_status(int wstatus);

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
