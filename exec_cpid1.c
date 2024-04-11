/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cpid1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:34:13 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/11 17:31:55 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	access_child1_file(char *arg, t_args args, int pipefd[])
{
	int	infile_fd;

	if (access(arg, F_OK) == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), arg);
		free_args(&args);
		close(pipefd[0]);
		close(pipefd[1]);
		exit (EXIT_FAILURE);
	}
	if (access(arg, R_OK) == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), arg);
		free_args(&args);
		close(pipefd[0]);
		close(pipefd[1]);
		exit (EXIT_FAILURE);
	}
	infile_fd = open(arg, O_RDONLY);
	if (infile_fd == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), arg);
		free_args(&args);
		close(pipefd[0]);
		close(pipefd[1]);
		exit (EXIT_FAILURE);
	}
	return (infile_fd);
}

static void	exec_child1_cmd(int fd, t_args args, char *envp[], int pipefd[])
{
	char	**tab;
	char	*all_pathes;
	char	*cmd_path;

	// tab = ft_split(cmd, " ");
	// if (!tab)
	// {
	// 	ft_putendl_fd("Problem allocating memory.", 2);
	// 	exit (EXIT_FAILURE);
	// }
	tab = args.cmd->content;
	if (tab[0] == NULL)
	{
		ft_printf(2, "zsh: command not found: \n");
		free_args(&args);
		close(pipefd[1]);
		close(fd);
		exit (127);
	}
	if (access(tab[0], F_OK | X_OK) == 0)
		cmd_path = tab[0];
	else if (ft_strchr(tab[0], '/') && access(tab[0], F_OK) == 0 && access(tab[0], X_OK) == -1 )
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), tab[0]);
		free_args(&args);
		close(pipefd[1]);
		close(fd);
		exit (126);
	}
	else
	{
		if (*envp == NULL)
		{
			free_args(&args);
			close(pipefd[1]);
			close(fd);
			exit (127);
		}
		all_pathes = get_envp_path(envp);
		if (!all_pathes)
		{
			free_args(&args);
			close(pipefd[1]);
			close(fd);
			exit (EXIT_FAILURE);
		}
		cmd_path = get_cmd_path(tab[0], all_pathes);
		if (!cmd_path)
		{
			ft_printf(2, "zsh: command not found: %s\n", tab[0]);
			free_args(&args);
			close(pipefd[1]);
			close(fd);
			exit (127);
		}
	}
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		free_args(&args);
		close(pipefd[1]);
		close(fd);
		exit (EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		free_args(&args);
		close(pipefd[1]);
		close(fd);
		exit (EXIT_FAILURE);
	}
	close(pipefd[1]);
	close(fd);
	execve(cmd_path, tab, NULL);
	perror("execve");
	exit (EXIT_FAILURE);
}

void	exec_cpid1(t_args args, char *envp[], int pipefd[])
{
	int	infile_fd;

	// ft_printf(1, "Child 1 executing\n");
	infile_fd = access_child1_file(args.file1, args, pipefd);
	exec_child1_cmd(infile_fd, args, envp, pipefd);
}
