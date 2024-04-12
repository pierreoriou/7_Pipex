/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:33:31 by peoriou           #+#    #+#             */
/*   Updated: 2024/04/03 13:50:04 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	if (!s || n == 0)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*result;

// 	str = "Bonjour";
// 	result = ft_strndup(str, 0);
// 	if (result)
// 		printf("%s\n", result);
// 	else
// 		printf("Result is NULL\n");
// 	free (result);
// 	return (0);
// }
