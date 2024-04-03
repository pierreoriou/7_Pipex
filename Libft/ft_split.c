/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:56:27 by poriou            #+#    #+#             */
/*   Updated: 2024/04/03 14:01:19 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ftsplit_strndup(const char *s, size_t n)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	dup = ft_memcpy(dup, s, n);
	dup[n] = '\0';
	return (dup);
}

static char	**ft_checkleaks(char **arr, int k)
{
	if (!arr[k])
	{
		while (k > 0)
			free(arr[k--]);
		free(arr);
		return (NULL);
	}
	return (arr);
}

static char	**ft_extractwords(char **arr, char const *s, char *charset)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (ft_ischarset(s[i], charset))
			i++;
		j = i;
		while (s[i] && !ft_ischarset(s[i], charset))
			i++;
		if (i > j)
		{
			arr[k] = ftsplit_strndup(s + j, i - j);
			if (ft_checkleaks(arr, k) == NULL)
				return (NULL);
			k++;
		}
	}
	arr[k] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char *set)
{
	char	**arr;

	if (s == 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_countwords((char *)s, set) + 1));
	if (!arr)
		return (NULL);
	arr = ft_extractwords(arr, s, set);
	return (arr);
}
