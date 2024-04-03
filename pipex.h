/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:04:11 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 10:10:21 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <sys/wait.h>
// REMOVE below !!
# include <stdio.h>

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

int		main(int argc, char *argv[]);
/* PARSING */
void	parse_args(char **tab);
void	parse_file1(char *file);
void	check_filename_isempty(char *file);
void	check_filename_isspace(char *file);
void	check_filename_characters(char *file, int n);
char	*trim_arg(char *arg);
void	check_filename_len(char *file);
void	check_file1_exists(char *file);
void	check_file1_isdir(char *file);
void	check_file1_permissions(char *file);
/* TESTS */
int		main_test_argc(void);

#endif
