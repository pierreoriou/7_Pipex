/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:52:58 by poriou            #+#    #+#             */
/*   Updated: 2024/03/08 10:43:24 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	adapt_result(int *sign)
{
	if (*sign == 1)
		return (LONG_MAX);
	else
	{
		*sign = 1;
		return (LONG_MIN);
	}
}

int	iterate(const char *nptr, int *sign)
{
	int	i;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	beyond_limits(const char *nptr)
{
	int	i;

	i = 0;
	while (ft_isdigit(nptr[i]))
		i++;
	if (i > 19)
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	unsigned long	result;
	int				sign;
	int				i;

	if (nptr == NULL)
		return (0);
	result = 0;
	sign = 1;
	i = iterate(nptr, &sign);
	if (beyond_limits(nptr + i) && sign)
		return (LONG_MAX);
	if (beyond_limits(nptr + i) && !sign)
		return (LONG_MIN);
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	if (result > LONG_MAX)
		result = adapt_result(&sign);
	result *= sign;
	return ((long)result);
}

// int	main(void)
// {
// 	char	*nb;
// 	long		my_result;
// 	long		real_result;

// 	nb = "9223372036854775806";
// 	my_result = ft_atol(nb);
// 	real_result = atol(nb);
// 	printf("My res  : %ld\n", my_result);
// 	printf("Real res: %ld\n", real_result);
// 	return (0);
// }
