/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_cpid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:44:34 by poriou            #+#    #+#             */
/*   Updated: 2024/04/12 12:06:00 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_exit_cpid(t_args args, int pipefd, int fd, int exitcode)
{
	free_args(&args);
	close(pipefd);
	close(fd);
	exit (exitcode);
}
