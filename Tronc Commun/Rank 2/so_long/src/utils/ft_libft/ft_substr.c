/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:16:26 by bastienverd       #+#    #+#             */
/*   Updated: 2023/12/21 17:04:32 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, int start, int len)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest = ft_calloc(1, sizeof(char));
		return (dest);
	}
	if (len <= ft_strlen(s) && start + len <= ft_strlen(s))
		dest = ft_calloc(len + 1, sizeof(char));
	else
		dest = ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (s[start + i] && i < len)
	{
		dest[i] = s[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
