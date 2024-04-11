/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:26:33 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/11 16:37:02 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	free_cmd_and_tab(char *cmd, char **tab)
{
	free (cmd);
	ft_free_tab(tab);
}

static char	*get_true_path(char **tab, char *cmd)
{
	int		i;
	char	*joined_path;

	i = 0;
	while (tab[i])
	{
		joined_path = ft_strjoin(tab[i], cmd);
		if (!joined_path)
		{
			free_cmd_and_tab(cmd, tab);
			return (NULL);
		}
		if (access(joined_path, F_OK) == 0)
		{
			free_cmd_and_tab(cmd, tab);
			return (joined_path);
		}
		free (joined_path);
		i++;
	}
	free_cmd_and_tab(cmd, tab);
	return (NULL);
}

char	*get_cmd_path(char *cmd, char *path)
{
	char	**tab;
	char	*true_path;

	tab = ft_split(path, ":");
	if (!tab)
		return (NULL);
	cmd = ft_strjoin("/", cmd);
	if (!cmd)
		return (NULL);
	true_path = get_true_path(tab, cmd);
	return (true_path);
}
