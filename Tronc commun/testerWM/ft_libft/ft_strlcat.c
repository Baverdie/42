/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:47:32 by basverdi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/11/02 15:17:12 by basverdi         ###   ########.fr       */
=======
/*   Updated: 2023/11/02 15:12:39 by basverdi         ###   ########.fr       */
>>>>>>> 21186925629151fb153ac1fea34a48ac0c37cdce
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if (dst == NULL || size == 0)
		return (0);
	i = ft_strlen(dst);
	j = 0;
	dst_len = i;
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
