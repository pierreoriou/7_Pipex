/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:31:17 by poriou            #+#    #+#             */
/*   Updated: 2024/03/22 15:17:47 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_indexofbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

long	ft_atol_base(char *nb, char *base)
{
	int		base_len;
	int		i;
	long	result;
	long	sign;

	if (!ft_check_base(base))
		return (-1);
	base_len = ft_strlen(base);
	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nb[i]))
		i++;
	if (nb[i] == '+' || nb[i] == '-')
	{
		if (nb[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_ischarset(nb[i], base))
	{
		result = result * base_len + (ft_indexofbase(nb[i], base));
		i++;
	}
	return (result * sign);
}

// int	main(void)
// {
// 	long	res;

// 	res = ft_atol_base("-vn", "poneyvif");
// 	printf("res = %ld\n", res);
// 	return (0);
// }
