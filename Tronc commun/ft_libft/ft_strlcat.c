/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:47:32 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/01 12:07:39 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t dst_len;
	size_t src_len;

	if (size == 0)
		return(0);
	if (dst == NULL && size == 0)
		return (0);
	i = ft_strlen(dst);
	j = 0;
	dst_len = i;
	src_len = ft_strlen(src);
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	if (size <= dst_len)
		return (src_len + size);
	return (dst_len + src_len);
}
