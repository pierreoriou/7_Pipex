/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:58:42 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 12:32:11 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	handle_parent(pid_t pid)
{
    int    wstatus;
    int    exit_status;

	if (waitpid(pid, &wstatus, 0) == -1)
	{
		perror("Waitpid failed");
		exit (EXIT_FAILURE);
	}
	if (WIFEXITED(wstatus))
	{
		exit_status = WEXITSTATUS(wstatus);
		if (exit_status == EXIT_SUCCESS) {
			ft_printf(1, "%31?\n", "KO");
		} else if (exit_status == EXIT_FAILURE) {
			ft_printf(1, "%32?\n", "OK");
		} else {
			printf("Child process exited with status %d\n", exit_status);
		}
	}
	else
	{
		printf("Child process terminated abnormally\n");
	}
}
