/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:26:05 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 09:23:00 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	length;

	length = ft_strlen(dest);
	if (length >= size)
		length = size;
	if (length == size)
		return (length + ft_strlen(src));
	return (length + ft_strlcpy(dest + length, src, size - length));
}
