/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:50:25 by poriou            #+#    #+#             */
/*   Updated: 2024/04/12 17:12:42 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	initiate_fork(t_args args, int pipefd[])
{
	pid_t	cpid;

	cpid = fork();
	if (cpid < 0)
	{
		perror("fork");
		free_exit_cpid(args, pipefd[0], pipefd[1], EXIT_FAILURE);
	}
	return (cpid);
}
