/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:34:13 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/10 08:42:52 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	access_child_file(t_args *args, char *arg)
{
	if (access(arg, F_OK) == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), arg);
		return ;
	}
	if (access(arg, R_OK) == -1)
	{
		perror("zsh");
		return ;
	}
	args->file1_ok = true;
	args->file1 = arg;
}

void	exec_child_cmd(t_args *args, char *cmd, char *envp[])
{
	char	**tab;
	char	*all_pathes;
	char	*cmd_path;

	tab = ft_split(cmd, " ");
	if (!tab)
	{
		ft_putendl_fd("Problem allocating memory.", 2);
		exit (EXIT_FAILURE);
	}
	all_pathes = get_envp_path(envp);
	if (!all_pathes)
	{
		ft_free_tab(tab);
		exit (1);
	}
	// printf("path = %s\n", all_pathes);
	cmd_path = get_cmd_path(tab[0], all_pathes);
	args->cmd_path_1 = cmd_path;
	// ERROR MESSAGE !!!!!
	// if (!cmd_path)
	// {
	// 	ft_free_tab(tab);
	// 	// msg
	// 	exit (1);
	// }

	if (cmd_path)
		execve(cmd_path, tab, NULL);
	else
	{
		errno = 127;
		// execve("/home/bin/grepzz", tab, NULL);
		perror("test");
	}
	printf("cmd_path = %s\n", cmd_path);
	// print_args(envp);
	exit (EXIT_FAILURE);
}

int	exec_cpid(t_args *args, char *argv[], char *envp[])
{
	access_child_file(args, argv[1]);
	if (args->file1_ok)
	{
		printf("Child file accessed...\n");
		exec_child_cmd(args, argv[2], envp);
	}
	return (42);
}
