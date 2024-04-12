/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dup2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:29:13 by poriou            #+#    #+#             */
/*   Updated: 2024/04/12 10:38:42 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_dup2_cpid1(t_args args, int pipefd, int infile_fd)
{
	if (dup2(pipefd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		free_exit_cpid(args, pipefd, infile_fd, EXIT_FAILURE);
	}
	if (dup2(infile_fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		free_exit_cpid(args, pipefd, infile_fd, EXIT_FAILURE);
	}
}

void	init_dup2_cpid2(t_args args, int pipefd, int outfile_fd)
{
	if (dup2(pipefd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		free_exit_cpid(args, pipefd, outfile_fd, EXIT_FAILURE);
	}
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		free_exit_cpid(args, pipefd, outfile_fd, EXIT_FAILURE);
	}
}
