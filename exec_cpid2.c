/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cpid2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:34:13 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/11 17:31:49 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_child2_cmd(int outfile_fd, t_args args, char *envp[], int pipefd[])
{
	char	**tab;
	char	*all_pathes;
	char	*cmd_path;

	tab = args.cmd->next->content;
	if (tab[0] == NULL)
	{
		ft_printf(2, "zsh: command not found: \n");
		free_args(&args);
		close(pipefd[0]);
		close(outfile_fd);
		exit (127);
	}
	if (access(tab[0], F_OK | X_OK) == 0)
		cmd_path = tab[0];
	else if (ft_strchr(tab[0], '/') && (access(tab[0], F_OK) == 0) && (access(tab[0], X_OK) == -1))
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), tab[0]);
		free_args(&args);
		close(pipefd[0]);
		close(outfile_fd);
		exit (126);
	}
	else
	{
		if (*envp == NULL)
		{
			free_args(&args);
			close(pipefd[0]);
			close(outfile_fd);
			exit (127);
		}
		all_pathes = get_envp_path(envp);
		if (!all_pathes)
		{
			ft_free_tab(tab);
			free_args(&args);
			close(pipefd[0]);
			close(outfile_fd);
			exit (EXIT_FAILURE);
		}
		cmd_path = get_cmd_path(tab[0], all_pathes);
		if (!cmd_path)
		{
			ft_printf(2, "zsh: command not found: %s\n", tab[0]);
			free_args(&args);
			close(pipefd[0]);
			close(outfile_fd);
			exit (127);
		}
	}
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		free_args(&args);
		close(pipefd[0]);
		close(outfile_fd);
		exit (EXIT_FAILURE);
	}
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		free_args(&args);
		close(pipefd[0]);
		close(outfile_fd);
		exit (EXIT_FAILURE);
	}
	close(pipefd[0]);
	close(outfile_fd);
	execve(cmd_path, tab, NULL);
	perror("execve");
	exit (EXIT_FAILURE);
}

static int	get_child2_file(char *file, t_args args, int *pipefd)
{
	int	outfile_fd;

	if (access(file, F_OK) == 0)
	{
		outfile_fd = open(file, O_WRONLY);
		if (outfile_fd == -1)
		{
			ft_printf(2, "zsh: %s: %s\n", strerror(errno), file);
			free_args(&args);
			close(pipefd[0]);
			close(pipefd[1]);
			exit (EXIT_FAILURE);
		}
		return (outfile_fd);
	}
	outfile_fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 00666);
	if (outfile_fd == -1)
	{
		ft_printf(2, "zsh: %s: %s\n", strerror(errno), file);
		free_args(&args);
		close(pipefd[0]);
		close(pipefd[1]);
		exit (EXIT_FAILURE);
	}
	return (outfile_fd);
}

void	exec_cpid2(t_args args, char *envp[], int pipefd[])
{
	int	outfile_fd;

	// ft_printf(1, "Child 2 executing\n");
	outfile_fd = get_child2_file(args.file2, args, pipefd);
	exec_child2_cmd(outfile_fd, args, envp, pipefd);
}
