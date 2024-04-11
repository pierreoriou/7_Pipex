/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cpid_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 07:54:36 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/11 09:54:40 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_cpid_status(int wstatus)
{
	if (WIFEXITED(wstatus))
		printf("last cpid ends with exit status : %d.\n", WEXITSTATUS(wstatus));
	if (WIFSIGNALED(wstatus))
		printf("last cpid ends with a signal %d.\n", WTERMSIG(wstatus));
}
