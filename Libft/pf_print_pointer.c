/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:14:31 by poriou            #+#    #+#             */
/*   Updated: 2024/04/11 11:49:23 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_print_pointer(t_print *tab)
{
	void	*p;
	char	*hexa;
	int		ptr;

	hexa = "0123456789abcdef";
	p = va_arg(tab->args, void *);
	if (p == NULL)
		tab->total_length += write(tab->fd, "(nil)", 5);
	else
	{
		tab->total_length += write(tab->fd, "0x", 2);
		ptr = pf_itoa_base((unsigned long int)p, hexa, tab);
		if (ptr == 0)
		{
			tab->error = 1;
			return ;
		}
		tab->total_length += ptr;
	}
	tab->width = 0;
	tab->color = 0;
}
