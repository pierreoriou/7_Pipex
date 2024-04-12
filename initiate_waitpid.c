/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_waitpid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:57:36 by poriou            #+#    #+#             */
/*   Updated: 2024/04/12 16:02:55 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int initiate_waitpid(pid_t pid, int *wstatus) {
    pid_t terminated_pid;

    terminated_pid = waitpid(pid, wstatus, 0);
    if (terminated_pid == -1) {
        if (errno != ECHILD) { // Check if the error is not due to no child processes
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
    }
    return terminated_pid;
}

// void	initiate_waitpid(pid_t pid, int *wstatus)
// {
// 	pid_t	terminated_pid;

// 	terminated_pid = waitpid(pid, wstatus, 0);
// 	if (terminated_pid == -1)
// 	{
// 		perror("waitpid");
// 		exit (EXIT_FAILURE);
// 	}
// }

void	initiate_waitpid2(int *wstatus)
{
	pid_t	terminated_pid;

	terminated_pid = waitpid(-1, wstatus, 0);
	if (terminated_pid == -1)
	{
		perror("waitpid");
		exit (EXIT_FAILURE);
	}
}
