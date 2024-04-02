/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_isdir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:51:31 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/02 14:26:35 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_file1_isdir(char *file)
{
	int	fd;

	fd = open(file, __O_DIRECTORY);
	if (fd != -1)
	{
		free (file);
		close (fd);
		ft_putendl_fd("Argument is a directory, when file expected.", 2);
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit (EXIT_FAILURE);
	}
}
