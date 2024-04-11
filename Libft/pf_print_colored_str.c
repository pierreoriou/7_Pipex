/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_colored_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:58:46 by poriou            #+#    #+#             */
/*   Updated: 2024/04/11 11:38:21 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_colored_print(t_print *tab, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		tab->total_length += write(tab->fd, &str[i], 1);
		i++;
	}
	tab->total_length -= 11;
}

char	*attach_color_prefix(t_print *tab, char *color)
{
	char	*new;

	new = ft_strjoin("\033[1;", color);
	if (!new)
	{
		free(color);
		tab->error = 1;
		return (NULL);
	}
	return (new);
}

char	*attach_color_suffix(t_print *tab, char *color)
{
	char	*new;

	new = ft_strjoin(color, "m");
	if (!new)
	{
		free(color);
		tab->error = 1;
		return (NULL);
	}
	free(color);
	return (new);
}

char	*attach_color_to_string(t_print *tab, char *color, char *str)
{
	char	*new;

	new = ft_strjoin(color, str);
	if (!new)
	{
		free(color);
		tab->error = 1;
		return (NULL);
	}
	free(color);
	return (new);
}

char	*attach_end_of_string(t_print *tab, char *color)
{
	char	*new;

	new = ft_strjoin(color, "\033[0m");
	if (!new)
	{
		free(color);
		tab->error = 1;
		return (NULL);
	}
	free(color);
	return (new);
}

void	pf_print_colored_str(t_print *tab)
{
	char	*str;
	char	*tmp_1;
	char	*tmp_2;
	char	*color;

	str = va_arg(tab->args, char *);
	if (str == NULL)
		str = "(null)";
	if (tab->width != 0)
	{
		color = ft_itoa(tab->width);
		if (!color)
			return ;
		tmp_1 = attach_color_prefix(tab, color);
		if (!tmp_1)
			return ;
		tmp_2 = attach_color_suffix(tab, tmp_1);
		if (!tmp_2)
			return ;
		tmp_1 = attach_color_to_string(tab, tmp_2, str);
		if (!tmp_1)
			return ;
		str = attach_end_of_string(tab, tmp_1);
		if (!str)
			return ;
	}
	pf_colored_print(tab, str);
	free(str);
	tab->width = 0;
	tab->color = 0;
}
