/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:17:58 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 16:15:57 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include "./Libft_copy/libft.h"
# include <sys/wait.h>

int		main(void);
void	fork_this(char *args[]);
void	handle_parent(pid_t pid);
void	test1_parsing_file1(void);
void	test1_parsing_cmd1(void);

#endif
