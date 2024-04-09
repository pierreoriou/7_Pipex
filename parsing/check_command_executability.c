/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_executability.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:26:33 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/09 12:42:14 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_envp_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd, char *path)
{
	char	**tab;
	char	*joined_path;
	int		i;

	tab = ft_split(path, ":");
	(void)cmd;
	if (!tab)
		return (NULL);
	i = 0;
	cmd = ft_strjoin("/", cmd);
	if (!cmd)
		return (NULL);
	while (tab[i])
	{
		joined_path = ft_strjoin(tab[i], cmd);
		if (!joined_path)
		{
			free (cmd);
			ft_free_tab(tab);
			return (NULL);
		}
		if (access(joined_path, F_OK | X_OK) == 0)
		{
			free (cmd);
			ft_free_tab(tab);
			return (joined_path);
		}
		free (joined_path);
		i++;
	}
	free (cmd);
	ft_free_tab(tab);
	return (NULL);
}

void	check_command_executability(char *cmd, t_args *args, char *envp[])
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
	cmd_path = find_cmd_path(tab[0], all_pathes);
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
