/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_exists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:39:29 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 11:22:05 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_file1_exists(char *file)
{
	if (access(file, F_OK) == -1)
	{
		free (file);
		perror("Error file1");
		exit (EXIT_FAILURE);
	}
}
