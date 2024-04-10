/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_isempty.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:39:19 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 16:13:33 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_command_isempty(char *cmd)
{
	int	len;

	len = ft_strlen(cmd);
	if (len == 0)
	{
		ft_putendl_fd("Command string is empty.", 2);
		exit (EXIT_FAILURE);
	}
}
