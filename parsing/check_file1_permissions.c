/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file1_permissions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:48:34 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/02 17:09:42 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_file1_permissions(char *file)
{
	if (access(file, R_OK) == -1)
	{
		free (file);
		perror("Error, file1 has no read permission");
		exit (EXIT_FAILURE);
	}
}
