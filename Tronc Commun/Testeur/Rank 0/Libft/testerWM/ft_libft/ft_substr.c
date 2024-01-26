/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 01:16:26 by bastienverd       #+#    #+#             */
/*   Updated: 2023/11/02 01:29:01 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest[0] = '\0';
		return (dest);
	}
	while (s[start] && len > 0)
	{
		dest[i] = s[start];
		i++;
		start++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
