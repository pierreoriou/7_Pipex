/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:40:15 by poriou            #+#    #+#             */
/*   Updated: 2024/04/09 10:32:33 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free (ptr);
		return (NULL);
	}
	new = (void *)malloc(new_size);
	if (!new)
		return (NULL);
	if (new_size > old_size)
		new = ft_memcpy(new, ptr, old_size);
	else
		new = ft_memcpy(new, ptr, new_size);
	free (ptr);
	return (new);
}

// int	main(void)
// {
// 	char	*init;
// 	char	*str;
// 	int		len;
// 	int		new_len;

// 	init = "Hello";
// 	str = ft_strdup(init);
// 	printf("BEFORE str = %s || %p\n", str, str);
// 	len = ft_strlen(str);
// 	new_len = 1;
// 	str = ft_realloc(str, len, new_len);
// 	// str = realloc(str, new_len);
// 	printf("RESULT str = %s || %p\n", str, str);
// 	free (str);
// 	return (0);
// }
