/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:52:00 by basverdi          #+#    #+#             */
/*   Updated: 2023/10/31 02:02:06 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t  k;

    i = 0;
    j = ft_strlen(dst);
    k = ft_strlen(src);
    if (size == 0 || j == size)
        return (k + j);
    if (size == 1)
    {
        dst[i] = 0;
        return (k + j);
    }
    while (src[i] && i < size - 1)
    {
        dst[i + j] = src[i];
        i++;
        
    }
    dst[i + j] = '\0';
    return (ft_strlen(src) + ft_strlen(dst));
}

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t j;
    size_t dst_len;
    size_t src_len;

    i = 0;
    j = 0;
    dst_len = strlen(dst);
    src_len = strlen(src);
    if (size <= dst_len)
        return (src_len + size);
    while (dst[i])
        i++;
    while (src[j] && i < size - 1)
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = '\0';
    return (dst_len + src_len);   
}

# include <stdio.h>
# include <string.h>
# include <stddef.h>

int main() {
    char buffer1[30] = "Hello";
    char buffer2[30] = "Goodbye";

    printf("Before strlcat:\n");
    printf("Buffer1: %s\n", buffer1);
    printf("Buffer2: %s\n", buffer2);

    strlcat(buffer1, ", World!", sizeof(buffer1));
    strlcat(buffer2, ", Universe!", sizeof(buffer2));

    printf("\nAfter strlcat:\n");
    printf("Buffer1: %s\n", buffer1);  // Outputs: Hello, World!
    printf("Buffer2: %s\n", buffer2);  // Outputs: Goodbye, Universe!

    // Edge case: destination buffer size is smaller than the initial content
    char buffer3[5] = "Hello";
    strlcat(buffer3, ", World!", sizeof(buffer3));
    printf("\nBuffer3 (edge case): %s\n", buffer3);  // Outputs: Hell

    return 0;
}