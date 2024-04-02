/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_hexau.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:30:04 by poriou            #+#    #+#             */
/*   Updated: 2024/03/04 10:25:28 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_print_hexau(t_print *tab)
{
	unsigned int	xu;

	xu = va_arg(tab->args, unsigned int);
	tab->total_length += pf_itoa_base(xu, "0123456789ABCDEF", tab);
	tab->width = 0;
	tab->color = 0;
}
