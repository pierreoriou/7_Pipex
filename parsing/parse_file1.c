/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:00:45 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/09 13:40:58 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parse_file1(char *arg, t_args *args)
{
	// check_filename_isempty(arg);
	// check_filename_isspace(arg);
	// check_filename_characters(arg, 1);
	// file = trim_arg(arg);
	// check_filename_len(file);
	// check_file1_isdir(file);
	if (access(arg, F_OK) == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), arg);
		// perror("zsh");
		return ;
	}
	if (access(arg, R_OK) == -1)
	{
		perror("zsh");
		return ;
	}
	// check_file1_exists(arg);
	// check_file1_permissions(arg);
	// printf("Allowed to READ %s.\n", file);
	args->file1_ok = true;
	args->file1 = arg;
}
