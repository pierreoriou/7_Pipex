/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cpid2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:34:13 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/12 17:08:52 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_child2_file(char *file, t_args args, int *pipefd)
{
	int	outfile_fd;

	if (access(file, F_OK) == 0)
	{
		outfile_fd = open(file, O_WRONLY);
		if (outfile_fd == -1)
		{
			ft_printf(2, "zsh: %s: %s\n", strerror(errno), file);
			free_exit_cpid(args, pipefd[0], pipefd[1], EXIT_FAILURE);
		}
		return (outfile_fd);
	}
	outfile_fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 00666);
	if (outfile_fd == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), file);
		free_exit_cpid(args, pipefd[0], pipefd[1], EXIT_FAILURE);
	}
	return (outfile_fd);
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

	cmd = args.cmd->next->content[0];
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
	return (get_cmd2_path(args, all_pathes, pipefd, fd));
}

static void	exec_child2_cmd(int fd, t_args args, char *envp[], int pipefd[])
{
	char	**tab;
	char	*cmd_path;

	tab = args.cmd->next->content;
	if (tab[0] == NULL)
	{
		ft_printf(2, "zsh: command not found: \n");
		free_exit_cpid(args, pipefd[0], fd, 127);
	}
	cmd_path = check_path_access(args, envp, pipefd[0], fd);
	init_dup2_cpid2(args, pipefd[0], fd);
	close_both_fd(pipefd[0], fd);
	execve(cmd_path, tab, NULL);
	perror("execve");
	exit (EXIT_FAILURE);
}

void	exec_cpid2(t_args *args, char *envp[], int pipefd[])
{
	int	outfile_fd;

	// ft_printf(1, "Child 2 executing\n");
	outfile_fd = get_child2_file(args->file2, *args, pipefd);
	close(pipefd[1]);
	exec_child2_cmd(outfile_fd, *args, envp, pipefd);
}
