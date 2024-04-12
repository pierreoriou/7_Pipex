/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cpid1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:34:13 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/12 17:08:58 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	access_child1_file(char *arg, t_args args, int pipefd[])
{
	int	infile_fd;

	if (access(arg, F_OK | R_OK) == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), arg);
		free_exit_cpid(args, pipefd[0], pipefd[1], EXIT_FAILURE);
	}
	infile_fd = open(arg, O_RDONLY);
	if (infile_fd == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), arg);
		free_exit_cpid(args, pipefd[0], pipefd[1], EXIT_FAILURE);
	}
	return (infile_fd);
}

static void	check_raw_path(t_args args, char *cmd, int pipefd, int fd)
{
	if (access(cmd, F_OK) == -1)
	{
		// ft_printf(2, "zsh: command not found: %s\n", cmd);
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), cmd);
		free_exit_cpid(args, pipefd, fd, 127);
	}
	if (access(cmd, X_OK) == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), cmd);
		free_exit_cpid(args, pipefd, fd, 126);
	}
}

static char	*check_path_access(t_args args, char *envp[], int pipefd, int fd)
{
	char	*all_pathes;
	char	*cmd;

	cmd = args.cmd->content[0];
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	else if (ft_strchr(cmd, '/'))
		check_raw_path(args, cmd, pipefd, fd);
	else
	{
		all_pathes = get_envp_path(envp);
		if (!all_pathes)
		{
			ft_printf(2, "zsh: command not found: %s\n", cmd);
			free_exit_cpid(args, pipefd, fd, 127);
		}
	}
	return (get_cmd1_path(args, all_pathes, pipefd, fd));
}

static void	exec_child1_cmd(int fd, t_args args, char *envp[], int pipefd[])
{
	char	**tab;
	char	*cmd_path;

	tab = args.cmd->content;
	if (tab[0] == NULL)
	{
		ft_printf(2, "zsh: command not found: \n");
		free_exit_cpid(args, pipefd[1], fd, 127);
	}
	cmd_path = check_path_access(args, envp, pipefd[1], fd);
	init_dup2_cpid1(args, pipefd[1], fd);
	close_both_fd(pipefd[1], fd);
	execve(cmd_path, tab, NULL);
	perror("execve");
	exit (EXIT_FAILURE);
}

void	exec_cpid1(t_args *args, char *envp[], int pipefd[])
{
	int	infile_fd;

	// ft_printf(1, "Child 1 executing\n");
	infile_fd = access_child1_file(args->file1, *args, pipefd);
	close(pipefd[0]);
	exec_child1_cmd(infile_fd, *args, envp, pipefd);
}
