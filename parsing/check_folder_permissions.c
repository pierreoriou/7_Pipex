/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_folder_permissions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:56:06 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 15:08:11 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	folder_to_come(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

static void	check_folder_access(char *folder, char *file)
{
	if (access(folder, F_OK) == -1)
	{
		free (file);
		free (folder);
		perror("Error, folder does not exist.");
		exit (EXIT_FAILURE);
	}
	if (access(folder, R_OK | X_OK) == -1)
	{
		free (file);
		free (folder);
		perror("Error, access.");
		exit (EXIT_FAILURE);
	}
}

void	check_folder_permissions(char *file)
{
	int		i;
	char	*folder;

	i = 0;
	while (file[i])
	{
		if (file[i] == '/')
		{
			folder = ft_strndup(file, i);
			if (!folder)
			{
				free (file);
				ft_putendl_fd("Problem allocating memory.", 2);
				exit (EXIT_FAILURE);
			}
			check_folder_access(folder, file);
			free (folder);
			if (!folder_to_come(file + i + 1))
				break ;
		}
		i++;
	}
}
