/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:33:52 by baverdie          #+#    #+#             */
/*   Updated: 2022/08/04 13:32:11 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dupstr;
	int		i;

	dupstr = malloc(ft_strlen(src) * sizeof(char) + 1);
	i = 0;
	while (src[i])
	{
		dupstr[i] = src[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}
