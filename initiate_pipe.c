/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:07:54 by poriou            #+#    #+#             */
/*   Updated: 2024/04/12 17:16:17 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initiate_pipe(int pipefd[2], t_args args)
{
	if (pipe(pipefd) == -1)
	{
		free_args(&args);
		perror("pipe");
		exit (EXIT_FAILURE);
	}
}
