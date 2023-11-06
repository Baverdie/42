/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 07:44:24 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 11:26:00 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*p_dest;

	p_dest = dest;
	while (*src && n)
	{
		*p_dest++ = *src++;
		n--;
	}
	while (n)
	{
		*p_dest++ = 0;
		n--;
	}
	return (dest);
}
