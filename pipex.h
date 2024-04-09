/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:04:11 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/09 14:57:39 by poriou           ###   ########.fr       */
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

int	main(int argc, char *argv[], char *envp[]);
/* PARSING F1 */
void	init_args(t_args *args);
void	parse_args(char *argv[], t_args *args, char *envp[]);
void	parse_file1(char *arg, t_args *args);
// void	check_filename_isempty(char *file);
// void	check_filename_isspace(char *file);
// void	check_filename_characters(char *file, int n);
// char	*trim_arg(char *arg);
// void	check_filename_len(char *file);
// void	check_file1_exists(char *file);
// void	check_file1_isdir(char *file);
void	check_file1_permissions(char *file);
void	check_folder_permissions(char *file);
/* PARSING CMD1 */
void	parse_command1(char *arg, t_args *args, char *envp[]);
void	check_command_isempty(char *cmd);
void	check_command_isspace(char *cmd);
void	check_command_executability(char *cmd, t_args *args, char *envp[]);
/* PRINTS */
void	print_args(char **arguments);

#endif
