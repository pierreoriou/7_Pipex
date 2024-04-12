/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing_cmd1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:18:02 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 17:26:33 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test1_parsing_cmd1(void)
{
	char **args[] = {
		// L'argument 2 ne doit pas être une chaine de caractères vide.
		(char *[]){"./pipex", "Files/file1.txt", "", "file2", "cmd2", NULL},
		// L'argument 2 ne doit pas être une chaine contenant que des espaces.
		(char *[]){"./pipex", "Files/file1.txt", "       ", "file2", "cmd2", NULL},
		// L'argument 2 doit etre une cmd executable.
		(char *[]){"./pipex", "Files/file1.txt", "lolilol", "file2", "cmd2", NULL},
		(char *[]){"./pipex", "Files/file1.txt", "ls -l -a", "file2", "cmd2", NULL},
	};

	for (size_t i = 0; i < sizeof(args) / sizeof(args[0]); i++)
	{
		fork_this(args[i]);
		sleep(1);
	}
}
