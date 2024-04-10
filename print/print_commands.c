/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:15:14 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/10 19:41:09 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_commands(t_cmd *cmd)
{
	int	i;
	int	count;

	if (!cmd)
		return ;
	count = 1;
	printf("--------------\n");
	while (cmd)
	{
		i = 0;
		ft_printf(1, "%33? %d:\n", "Commande", count);
		while (cmd->content[i])
		{
			printf("# cmd->content[%d]: %s\n", i, cmd->content[i]);
			i++;
		}
		printf("--------------\n");
		cmd = cmd->next;
		count++;
	}
}
