/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char_cat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:36:06 by vgodart           #+#    #+#             */
/*   Updated: 2023/07/29 19:47:19 by yalasbor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*ft_str_char_cat(char *dest, char src)
{
	int	dest_len;

	dest_len = ft_strlen(dest);
	dest[dest_len] = src;
	dest[dest_len + 1] = '\0';
	return (dest);
}
