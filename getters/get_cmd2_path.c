/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd2_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:26:33 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/12 15:20:02 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	free_cmd_and_tab(char *cmd, char **tab)
{
	free (cmd);
	ft_free_tab(tab);
}

static int	check_access(char *joined_path, char *cmd, char **tab)
{
	if (access(joined_path, F_OK) == 0)
	{
		free_cmd_and_tab(cmd, tab);
		return (1);
	}
	return (0);
}

static char	*get_true_path(t_args args, char **tab, int pipefd, int fd)
{
	int		i;
	char	*joined_path;
	char	*cmd;

	cmd = ft_strjoin("/", args.cmd->next->content[0]);
	if (!cmd)
		free_exit_cpid(args, pipefd, fd, EXIT_FAILURE);
	i = 0;
	while (tab[i])
	{
		joined_path = ft_strjoin(tab[i], cmd);
		if (!joined_path)
		{
			free_cmd_and_tab(cmd, tab);
			free_exit_cpid(args, pipefd, fd, EXIT_FAILURE);
		}
		if (check_access(joined_path, cmd, tab))
			return (joined_path);
		free (joined_path);
		i++;
	}
	free_cmd_and_tab(cmd, tab);
	ft_printf(2, "zsh: command not found: %s\n", args.cmd->next->content[0]);
	free_exit_cpid(args, pipefd, fd, 127);
	return (NULL);
}

char	*get_cmd2_path(t_args args, char *path, int pipefd, int fd)
{
	char	**tab;
	char	*true_path;

	tab = ft_split(path, ":");
	if (!tab)
		free_exit_cpid(args, pipefd, fd, EXIT_FAILURE);
	true_path = get_true_path(args, tab, pipefd, fd);
	return (true_path);
}
