/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:59:22 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/01 19:13:39 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*s;

	s = src;
	dst = dest;
	if (dst == NULL && s == NULL)
		return (0);
	if (dst < s)
		ft_memcpy(dst, s, n);
	else
	{
		while (n > 0)
		{
			dst[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}
