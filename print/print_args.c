/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:46:43 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/10 19:52:28 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_args(t_args *args)
{
	ft_printf(1, "%33?\n", "--PRINT ARGS--");
	printf("args->file1 = %s\n", args->file1);
	printf("args->file2 = %s\n", args->file2);
	print_commands(args->cmd);
}
