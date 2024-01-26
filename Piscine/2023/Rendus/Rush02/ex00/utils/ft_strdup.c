/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:33:58 by vgodart           #+#    #+#             */
/*   Updated: 2023/07/29 19:47:25 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_strdup(char *src, int pos1, int pos2)
{
	int		size;
	int		i;
	char	*result;

	i = 0;
	size = pos2 - pos1;
	result = malloc(sizeof(char) * size + 1);
	if (result == NULL)
		return (NULL);
	while (pos1 < pos2)
	{
		result[i] = src[pos1];
		i++;
		pos1++;
	}
	result[i] = '\0';
	return (result);
}
