/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:09:11 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 18:02:01 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parse_command1(char *arg, char *envp[])
{
	check_command_isempty(arg);
	check_command_isspace(arg);
	check_command_executability(arg, envp);
}
