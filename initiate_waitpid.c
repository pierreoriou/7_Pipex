/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_waitpid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:57:36 by poriou            #+#    #+#             */
/*   Updated: 2024/04/10 16:13:01 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initiate_waitpid(pid_t pid, int *wstatus)
{
	pid_t	terminated_pid;

	terminated_pid = waitpid(pid, wstatus, 0);
	if (terminated_pid == -1)
	{
		perror("waitpid");
		exit (EXIT_FAILURE);
	}
}
