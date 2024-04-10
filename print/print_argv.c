/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:15:06 by poriou            #+#    #+#             */
/*   Updated: 2024/04/10 19:46:12 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_argv(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		printf("arguments[%d] = %s\n", i, arguments[i]);
		i++;
	}
}
