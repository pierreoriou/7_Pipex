/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:57:41 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 10:46:01 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int main(void)
{
    pid_t   pid;
    int     wstatus;
    char *args[] = {"./pipex", "file1", "cmd1", "file2", "cmd2", NULL};

    pid = fork();
    if (pid == -1)
    {
        perror("Fork failed");
        exit (EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (execvp("./pipex", args) == -1)
            printf("OK ");
    }
    else
    {
        if (wait)
    }

    // If execvp returns, it means an error occurred
    perror("Test failed");
    printf("hello from testing\n");
    return (0);
}
