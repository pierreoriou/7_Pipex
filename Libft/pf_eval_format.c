/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:24:04 by poriou            #+#    #+#             */
/*   Updated: 2024/04/11 11:39:04 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_eval_format(t_print *tab, const char *str, int index)
{
	char	*charset;

	charset = "?cspdiuxX%";
	while (!ft_ischarset(str[index], charset))
	{
		if (str[index] >= '0' && str[index] <= '9')
		{
			if (ft_atoi(str + index) > tab->width)
				tab->width = ft_atoi(str + index);
		}
		index++;
	}
	pf_checkcase(tab, str[index]);
	if (tab->error)
		return (-1);
	return (index);
}
