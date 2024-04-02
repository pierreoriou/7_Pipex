/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:18:27 by poriou            #+#    #+#             */
/*   Updated: 2024/03/04 10:26:54 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_print_uint(t_print *tab)
{
	unsigned long	u;

	u = va_arg(tab->args, unsigned int);
	tab->total_length += pf_itoa_base(u, "0123456789", tab);
	tab->width = 0;
	tab->color = 0;
}
