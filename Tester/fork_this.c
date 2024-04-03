/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_this.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:25:47 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 11:58:02 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	fork_this(char *args[])
{
	pid_t	pid;

    pid = fork();
    if (pid == -1)
    {
        perror("Fork failed");
        exit (EXIT_FAILURE);
    }
	else if (pid == 0)
    {
        execvp("./pipex", args);
        perror("Test failed");
        exit (EXIT_FAILURE);
    }
	else
		handle_parent(pid);
}
