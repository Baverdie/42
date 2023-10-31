/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:47:32 by basverdi          #+#    #+#             */
/*   Updated: 2023/10/31 19:04:48 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t dst_len;
    size_t src_len;

    i = 0;
    j = 0;
    dst_len = ft_strlen(dst);
    src_len = ft_strlen(src);
    if (dst == NULL || size == 0)
        return (0);
    while (dst[i])
        i++;
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

#include <stdio.h>
// do a main to test for null and size 0

int main()
{
    char    *src;
    char    *dst;
    size_t  size;

    src = "hello";
    dst = "";
    size = 0;
    printf("%zu\n", ft_strlcat((void *)0, src, size));
    printf("%s\n", dst);
    return (0);
}