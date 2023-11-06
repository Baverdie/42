/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:45:51 by bastienverd       #+#    #+#             */
/*   Updated: 2023/11/06 09:49:40 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*src;

	i = 0;
	if (!s || n == 0)
		return (0);
	src = (char *)s;
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (src[i] && i < n)
	{
		if (src[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

#include <stdio.h>

int main(){
	char s[] = {1, 2, 3, 4, 5, 6};
	printf("", ft_memchr(s, 2, 3));
}