/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:50:25 by poriou            #+#    #+#             */
/*   Updated: 2024/04/10 15:12:05 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	initiate_fork(void)
{
	pid_t	cpid;

	cpid = fork();
	if (cpid < 0)
	{
		perror("fork");
		exit (EXIT_FAILURE);
	}
	return (cpid);
}
