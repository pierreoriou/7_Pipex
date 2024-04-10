/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:30:45 by poriou            #+#    #+#             */
/*   Updated: 2024/04/10 17:36:35 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_cmd	*cmdnew(char *content)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->content = ft_split(content);
	if (!new->content)
		return (NULL);
	new->next = NULL;
	return (new);
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
		new = cmdnew(argv[2]);
		cmd_addback(&(args->cmd), new);
		i++;
	}
	// protec
}
