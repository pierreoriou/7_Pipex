/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename_characters.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:56:49 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/02 16:46:11 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	is_authorized(char c)
{
	if (c == '-')
		return (1);
	if (c == '_')
		return (1);
	if (c == '.')
		return (1);
	if (c == '/')
		return (1);
	return (0);
}

static void	print_authorized_chars(void)
{
	ft_putendl_fd("=== Authorized characters below ===", 2);
	ft_putendl_fd("> a-z, A-Z (Alphabetical chars)", 2);
	ft_putendl_fd("> 0-9 (Numerical chars)", 2);
	ft_putendl_fd("> - (Hyphen or Dash)", 2);
	ft_putendl_fd("> _ (Underscore)", 2);
	ft_putendl_fd("> . (Period or Dot)", 2);
}

static void	print_unauthorized_char(char c, int index, int n)
{
	if (ft_isascii(c))
	{
		ft_putchar_fd(c, 2);
		ft_putstr_fd(" (ascii value: ", 2);
		ft_putnbr_fd(c, 2);
		ft_putstr_fd(")", 2);
	}
	else
	{
		ft_putstr_fd("non-ASCII character index ", 2);
		ft_putnbr_fd(index, 2);
		ft_putstr_fd(" of file ", 2);
		ft_putnbr_fd(n, 2);
	}
	ft_putendl_fd(": unauthorized.", 2);
}

void	check_filename_characters(char *file, int n)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (!ft_isalnum(file[i]) && !is_authorized(file[i]))
		{
			print_unauthorized_char(file[i], i, n);
			print_authorized_chars();
			exit (EXIT_FAILURE);
		}
		i++;
	}
}
