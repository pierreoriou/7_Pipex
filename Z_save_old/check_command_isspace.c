/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_isspace.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:39:19 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 16:14:13 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_command_isspace(char *cmd)
{
	int	len;
	int	i;

	len = ft_strlen(cmd);
	i = 0;
	while (ft_isspace(cmd[i]))
		i++;
	if (i == len)
	{
		ft_putendl_fd("Command string contains only spaces.", 2);
		exit (EXIT_FAILURE);
	}
}
