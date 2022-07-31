/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 08:14:53 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 08:23:32 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*p_dest;

	p_dest = dest + ft_strlen(dest);
	while (n-- && *src)
		*p_dest++ = *src++;
	*p_dest++ = '\0';
	return (dest);
}
