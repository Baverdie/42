/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 07:44:25 by baverdie          #+#    #+#             */
/*   Updated: 2022/08/04 13:32:48 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen_strs(char **strs, int size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (strs[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_strlen_sep(char *sep, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		while (sep[i])
			i++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*resstr;
	int		sizemalloc;

	i = 0;
	if (strs == NULL)
		return ("");
	sizemalloc = ft_strlen_strs(strs, size) + ft_strlen_sep(sep, size) * (size - 1);
	resstr = malloc(sizemalloc * sizeof(char) + 1);
	while (i < size)
	{
		resstr = ft_strcat(resstr, strs[i]);
		if (i < size - 1)
			resstr = ft_strcat(resstr, sep);
		i++;
	}
	return (resstr);
}
