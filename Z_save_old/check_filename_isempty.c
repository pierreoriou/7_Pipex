/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename_isempty.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:39:19 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/02 14:51:26 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_filename_isempty(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len == 0)
	{
		ft_putendl_fd("File name is empty.", 2);
		exit (EXIT_FAILURE);
	}
}
