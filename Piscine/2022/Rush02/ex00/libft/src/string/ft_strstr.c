/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:23:49 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 08:25:26 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	to_find_size;

	i = 0;
	j = 0;
	to_find_size = 0;
	while (needle[to_find_size])
		to_find_size++;
	if (to_find_size == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[j] == haystack[i + j])
		{
			if (j == to_find_size - 1)
				return ((char *)(haystack + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
