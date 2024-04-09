/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:52:23 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/09 13:10:54 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parse_args(char *argv[], t_args *args, char *envp[])
{
	parse_file1(argv[1], args);
	if (args->file1_ok)
		parse_command1(argv[2], args, envp);
	// parse_file2(argv[4], args);
	// parse_command2(argv[3], args, envp);
}
