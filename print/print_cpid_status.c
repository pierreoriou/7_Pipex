/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cpid_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:54:36 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/10 08:30:44 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_cpid_status(int wstatus)
{
	if (WIFEXITED(wstatus))
		printf("Child process ended with exit status : %d.\n", WEXITSTATUS(wstatus));
	if (WIFSIGNALED(wstatus))
		printf("Child process ended with a signal %d.\n", WTERMSIG(wstatus));
}
