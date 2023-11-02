/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:45:51 by bastienverd       #+#    #+#             */
/*   Updated: 2023/11/01 23:48:22 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*src;

	i = 0;
	if (!s)
		return (0);
	src = (char *)s;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (src[i] && i < n)
	{
		if (src[i] == c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return (0);
}
