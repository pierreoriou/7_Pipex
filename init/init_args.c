/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:30:45 by poriou            #+#    #+#             */
/*   Updated: 2024/04/09 13:28:33 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_args(t_args *args)
{
	args->file1 = NULL;
	args->file2 = NULL;
	args->cmd_path_1 = NULL;
	args->cmd_path_2 = NULL;
	args->file1_ok = false;
	args->file2_ok = false;
	args->cmd1_ok = false;
	args->cmd2_ok = false;
}
