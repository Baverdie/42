/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/11/02 11:57:46 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/02 15:31:56 by basverdi         ###   ########.fr       */
=======
/*   Created: 2023/11/03 15:13:38 by bastienverd       #+#    #+#             */
/*   Updated: 2023/11/03 17:05:52 by bastienverd      ###   ########.fr       */
>>>>>>> 21186925629151fb153ac1fea34a48ac0c37cdce
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
<<<<<<< HEAD
=======

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (*s && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_len_words(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char **ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

static char	**ft_tab(char **tab, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			tab[j] = malloc(sizeof(char) * (ft_len_words(&s[i], c) + 1));
			if (!tab[j])
				ft_free(tab, j);
			while ((s[i] && s[i] != c))
				tab[j][k++] = s[i++];
			tab[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	return (ft_tab(tab, s, c));
}
>>>>>>> 21186925629151fb153ac1fea34a48ac0c37cdce
