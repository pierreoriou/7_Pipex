/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:34:00 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/02 12:37:29 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*trim_arg(char *arg)
{
	char	*file;
	char	*space_set;

	space_set = " \t\n\v\f\r";
	file = ft_strtrim(arg, space_set);
	if (!file)
	{
		ft_putendl_fd("Problem allocating memory.", 2);
		exit (EXIT_FAILURE);
	}
	return (file);
}
