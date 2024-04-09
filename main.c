/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:03:07 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/09 16:31:13 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ft_printf(1, "End of main, Return (0);\n");
int	main(int argc, char *argv[], char *envp[])
{
	t_args	args;
	pid_t	pid;
	pid_t	terminated_pid;
	int		wstatus;

	// args = NULL;
	if (argc != 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit (EXIT_FAILURE);
	}
	(void)argv;
	(void)envp;
	(void)args;
	(void)terminated_pid;
	(void)wstatus;
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		sleep(2);
		printf("now child.\n");
		// init_args(&args);
		// parse_args(argv, &args, envp);
		// sleep(3);
		// printf("Child process over.\n");
		// sleep(1);
		return (0);
	}
	else
	{
		sleep(1);
		printf("now parent.\n");
		// printf("Back to parent process before waitpid.\n");
		// terminated_pid = waitpid(pid, &wstatus, 0);
		// printf("Back to parent process.\n");
		// sleep(1);
		// if (terminated_pid == -1)
		// 	perror("zsh:");
		// if (WIFEXITED(wstatus))
		// 	printf("Child process ended with exit status : %d.\n", WEXITSTATUS(wstatus));
		// if (WIFSIGNALED(wstatus))
		// 	printf("Child process ended with a signal %d.\n", WTERMSIG(wstatus));
	}
	return (0);
}
