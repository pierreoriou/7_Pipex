/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:04:11 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 18:02:25 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <sys/wait.h>

typedef struct s_args
{
	int		fd1;
	char	*fd1_name;
	bool	fd1_isdir;
	bool	fd1_isfile;
	bool	fd1_r_ok;
	bool	fd1_w_ok;
	bool	fd1_x_ok;
	int		fd2;
	bool	fd2_exists;
	bool	fd2_isdir;
	bool	fd2_isfile;
}			t_args;

int	main(int argc, char *argv[], char *envp[]);
/* PARSING F1 */
void	parse_args(char *argv[], char *envp[]);
void	parse_file1(char *file);
void	check_filename_isempty(char *file);
void	check_filename_isspace(char *file);
void	check_filename_characters(char *file, int n);
char	*trim_arg(char *arg);
void	check_filename_len(char *file);
void	check_file1_exists(char *file);
void	check_file1_isdir(char *file);
void	check_file1_permissions(char *file);
void	check_folder_permissions(char *file);
/* PARSING CMD1 */
void	parse_command1(char *arg, char *envp[]);
void	check_command_isempty(char *cmd);
void	check_command_isspace(char *cmd);
void	check_command_executability(char *cmd, char *envp[]);

#endif
