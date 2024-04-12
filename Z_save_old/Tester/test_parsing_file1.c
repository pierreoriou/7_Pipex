/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing_file1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:18:02 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/04 16:22:10 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test1_parsing_file1(void)
{
	char **args[] = {
		// Argc doit être 5.
		(char *[]){"./pipex", "cmd1", "file2", "cmd2", NULL},
		// L'argument 1 ne doit pas être une chaine de caractères vide.
		(char *[]){"./pipex", "", "cmd1", "file2", "cmd2", NULL},
		// L'argument 1 ne doit pas être une chaine contenant que des espaces.
		(char *[]){"./pipex", "        ", "cmd1", "file2", "cmd2", NULL},
		// L'argument 1 ne doit contenir que des caracteres autorisés.
		(char *[]){"./pipex", "aaaè", "cmd1", "file2", "cmd2", NULL},
		// L'argument 1 ne doit contenir que des caracteres autorisés.
		(char *[]){"./pipex", "aaa=", "cmd1", "file2", "cmd2", NULL},
		// L'argument 1 ne doit pas contenir plus de 255 caractères.
		(char *[]){"./pipex", "cbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "cmd1", "file2", "cmd2", NULL},
		// L'argument 1 doit être un chemin de fichier existant.
		(char *[]){"./pipex", "Files/filz.txt", "cmd1", "file2", "cmd2", NULL},
		// L'argument 1 doit être un chemin de fichier existant.
		(char *[]){"./pipex", "Filez/file1.txt", "cmd1", "file2", "cmd2", NULL},
		// L'argument 1 doit être le chemin d'un fichier et non d'un dossier.
		(char *[]){"./pipex", "Files", "cmd1", "file2", "cmd2", NULL}
		// a ajouter :
		// Les dossiers menant au fichier doivent avoir +w et +x
		// Le fichier doit avoir +w
	};

	for (size_t i = 0; i < sizeof(args) / sizeof(args[0]); i++)
	{
		fork_this(args[i]);
		sleep(1);
	}
}
