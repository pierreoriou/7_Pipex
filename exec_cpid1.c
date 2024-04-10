/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cpid1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:34:13 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/10 15:54:47 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	access_child1_file(char *arg)
{
	if (access(arg, F_OK) == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), arg);
		exit (1);
	}
	if (access(arg, R_OK) == -1)
	{
		perror("zsh");
		exit (1);
	}
}

void	exec_child1_cmd(char *cmd, char *envp[], int pipefd[])
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
	cmd_path = get_cmd_path(tab[0], all_pathes);
	if (!cmd_path)
	{
		ft_printf(2, "zsh: command not found: %s\n", cmd);
		return ;
	}
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		// free what needs to be freed
		exit (1);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	execve(cmd_path, tab, NULL);
	exit (EXIT_FAILURE);
}

int	exec_cpid1(char *argv[], char *envp[], int pipefd[])
{
	printf("Child process initiated...\n");
	access_child1_file(argv[1]);
	exec_child1_cmd(argv[2], envp, pipefd);
	return (42);
}
