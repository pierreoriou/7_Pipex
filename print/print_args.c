/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:15:06 by poriou            #+#    #+#             */
/*   Updated: 2024/04/09 10:22:29 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	print_args(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		printf("arguments[%d] = %s\n", i, arguments[i]);
		i++;
	}
}
