/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:30:45 by poriou            #+#    #+#             */
/*   Updated: 2024/04/11 09:52:58 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_cmd	*cmdnew(char *content)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->content = ft_split(content, " ");
	if (!new->content)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	cmd_addback(t_cmd **cmd, t_cmd *new)
{
	t_cmd	*tmp;

	if (!cmd)
		return ;
	if (!*cmd)
	{
		*cmd = new;
		return ;
	}
	tmp = *cmd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	init_args(t_args *args, int argc, char *argv[])
{
	t_cmd	*new;
	int		i;

	args->cmd = NULL;
	args->file1 = argv[1];
	args->file2 = argv[4];
	i = 2;
	while (i < (argc - 1))
	{
		new = cmdnew(argv[i]);
		if (!new)
		{
			free_args(args);
			exit (EXIT_FAILURE);
		}
		cmd_addback(&(args->cmd), new);
		i++;
	}
}
