/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:18:20 by bastienverd       #+#    #+#             */
/*   Updated: 2023/12/13 15:03:20 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	if (ft_strlen(s) == 1)
		str[i] = 0;
	while (s[i] && i < ft_strlen(s) - 1)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0' ;
	return (str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_substr(const char *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		dest = malloc(1 * sizeof(char));
	else if (ft_strlen(s) - start > len)
		dest = malloc(len + 1 * sizeof(char));
	else
		dest = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			dest[i] = s[i + start];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
