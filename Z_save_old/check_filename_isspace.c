/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename_isspace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:39:19 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/02 16:11:49 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_filename_isspace(char *file)
{
	int	len;
	int	i;

	len = ft_strlen(file);
	i = 0;
	while (ft_isspace(file[i]))
		i++;
	if (i == len)
	{
		ft_putendl_fd("File name contains only spaces.", 2);
		exit (EXIT_FAILURE);
	}
}
