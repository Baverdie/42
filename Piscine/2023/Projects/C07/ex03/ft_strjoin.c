/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:48:12 by basverdi          #+#    #+#             */
/*   Updated: 2023/07/31 17:01:56 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_str_tablen(char **strs, int size)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		i;
	int		len;

	i = 0;
	if (size == 0 || **strs == '\0')
	{
		tab = malloc(sizeof(char));
		return (tab);
	}
	len = ft_str_tablen(strs, size) + ft_strlen(sep) * (size - 1);
	tab = malloc((len + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (i < size)
	{
		ft_strcat(tab, strs[i]);
		if (i + 1 < size)
			ft_strcat(tab, sep);
		i++;
	}
	return (&*tab);
}
