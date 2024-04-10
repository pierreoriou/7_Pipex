/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:07:48 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/02 14:48:20 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_filename_len(char *file)
{
	int	len;

	// if (file[0] == '\0')
	// {
	// 	free (file);
	// 	ft_putendl_fd("File name is empty.", 2);
	// 	exit (EXIT_FAILURE);
	// }
	len = ft_strlen(file);
	if (file[len - 1] == '/')
	{
		free (file);
		ft_putendl_fd("Path leads to empty file name.", 2);
		exit (EXIT_FAILURE);
	}
	if (len > 255)
	{
		free (file);
		ft_putendl_fd("File path is too long.", 2);
		exit (EXIT_FAILURE);
	}
}
