/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:03:07 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/10 08:41:57 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_args	args;
	pid_t	cpid;
	pid_t	terminated_cpid;
	int		wstatus;

	if (argc != 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit (EXIT_FAILURE);
	}
	init_args(&args);
	cpid = fork();
	if (cpid < 0)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}
	else if (cpid == 0)
	{
		printf("Child process initiated...\n");
		exec_cpid(&args, argv, envp);
		return (42);
	}
	else
	{
		terminated_cpid = waitpid(cpid, &wstatus, 0);
		if (terminated_cpid == -1)
			perror("waitpid");
		printf("Back to parent process...\n");
		print_cpid_status(wstatus);
		// if (WIFEXITED(wstatus))
		// 	printf("Child process ended with exit status : %d.\n", WEXITSTATUS(wstatus));
		// if (WIFSIGNALED(wstatus))
		// 	printf("Child process ended with a signal %d.\n", WTERMSIG(wstatus));
	}
	return (0);
}
