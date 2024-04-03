/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:00:45 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 14:27:34 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parse_file1(char *arg)
{
	char	*file;

	check_filename_isempty(arg);
	check_filename_isspace(arg);
	check_filename_characters(arg, 1);
	file = trim_arg(arg);
	check_filename_len(file);
	check_file1_isdir(file);
	check_file1_permissions(file);
	check_file1_exists(file);
	printf("Allowed to READ %s.\n", file);
	free (file);
}
