/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:26:33 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/10 08:35:49 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_cmd_path(char *cmd, char *path)
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
