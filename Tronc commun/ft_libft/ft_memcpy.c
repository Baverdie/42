/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:00:32 by bastienverd       #+#    #+#             */
/*   Updated: 2023/11/01 12:16:58 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*s;

	i = 0;
	dst = dest;
	s = src;
	while (i <= n)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return(dest);
}
