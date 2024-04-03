/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_executability.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:26:33 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 18:17:59 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_args(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		printf("arguments[%d] = %s\n", i, arguments[i]);
		i++;
	}
}

void	check_command_executability(char *cmd, char *envp[])
{
	char	**tab;
	char *const args[] = {"ls", "-l", "-a", NULL};

	tab = ft_split(cmd, " ");
	if (!tab)
	{
		ft_putendl_fd("Problem allocating memory.", 2);
		exit (EXIT_FAILURE);
	}
	print_args(envp);
	execve("/usr/bin/cat", args, NULL);
	// execve(tab[0], tab + 1, NULL);
	perror("Cmd1");
	exit (EXIT_FAILURE);
}
