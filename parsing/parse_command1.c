/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:09:11 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/09 13:11:37 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parse_command1(char *arg, t_args *args, char *envp[])
{
	check_command_isempty(arg);
	check_command_isspace(arg);
	check_command_executability(arg, args, envp);
}
