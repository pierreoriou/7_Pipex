/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:06:17 by poriou            #+#    #+#             */
/*   Updated: 2024/04/11 10:36:19 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_args(t_args *args)
{
	t_cmd	*next;
	t_cmd	*tmp;

	if (args->cmd == NULL)
		return ;
	tmp = args->cmd;
	while (tmp)
	{
		next = tmp->next;
		ft_free_tab(tmp->content);
		free(tmp);
		tmp = next;
	}
	args->cmd = NULL;
}
