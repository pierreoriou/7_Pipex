/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cpid2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:34:13 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/10 15:51:27 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_child2_cmd(int outfile_fd, char *cmd, char *envp[], int pipefd[])
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
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		// free what needs to be freed
		exit (1);
	}
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit (EXIT_FAILURE);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(outfile_fd);
	execve(cmd_path, tab, NULL);
	exit (EXIT_FAILURE);
}

int	get_child2_file(char *file)
{
	int	fd;

	if (access(file, F_OK) == 0)
	{
		fd = open(file, O_WRONLY);
		if (fd == -1)
		{
			ft_printf(2, "zsh: %s: %s\n", strerror(errno), file);
			exit (1);
		}
		return (fd);
	}
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 00666);
	if (fd == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), file);
		exit (EXIT_FAILURE);
	}
	return (fd);
}

int	exec_cpid2(char *argv[], char *envp[], int pipefd[])
{
	int	outfile_fd;

	printf("Child process 2 initiated...\n");
	outfile_fd = get_child2_file(argv[4]);
	exec_child2_cmd(outfile_fd, argv[3], envp, pipefd);
	return (42);
}
