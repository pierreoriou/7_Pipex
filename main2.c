/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:03:07 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/12 17:15:19 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_args	args;
	pid_t	cpid1;
	pid_t	cpid2;
	int		wstatus;
	int		pipefd[2];
	int		status;

	if (argc != 5)
	{
		ft_putendl_fd("Usage: ./pipex file1 cmd1 cmd2 file2", 2);
		exit (EXIT_FAILURE);
	}
	init_args(&args, argc, argv);
	initiate_pipe(pipefd, args);
	cpid1 = initiate_fork(args, pipefd);
	if (cpid1 == 0)
		exec_cpid1(&args, envp, pipefd);
	cpid2 = initiate_fork(args, pipefd);
	if (cpid2 == 0)
		exec_cpid2(&args, envp, pipefd);
	close (pipefd[0]);
	close (pipefd[1]);
	status = 0;
	while (errno != ECHILD)
	{
		if(wait(&wstatus) == cpid2)
			status = WEXITSTATUS(wstatus);
	}
	free_args(&args);
	return (status);
}
