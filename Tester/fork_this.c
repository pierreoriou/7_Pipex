/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_this.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:25:47 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/04 16:33:51 by poriou           ###   ########.fr       */
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
        execvp("../piipex", args);
        perror("Test failed");
        exit (EXIT_FAILURE);
    }
	else
		handle_parent(pid);
}
