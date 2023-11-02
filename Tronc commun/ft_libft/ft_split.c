/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:57:46 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/02 14:27:55 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sep(const char *s, char sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != sep)
			i++;
		j++;
		i++;
	}
	return (j);
}

static int	ft_len(const char *s, char sep, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s && j < k)
	{
		if (s[i] == sep)
			j++;
		i++;
	}
	j = i;
	while (*s)
	{
		if (s[i] == sep)
			return (i - j);
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	size = ft_sep(s, c);
	tab = malloc(sizeof(char *) * size + 1);
	if (!tab)
		return (NULL);
	while (s && j <= size)
	{
		tab[j] = (sizeof(char *) * ft_len(s, c, size) + 1);
		while (s[i] != c)
		{
			tab[j][i] = s[i];
			i++;
		}
		j++;
	}
	j = 0;
	tab[i][j] = '\0';
	return (tab);
}
