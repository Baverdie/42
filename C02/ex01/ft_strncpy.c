/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 06:32:11 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/18 07:42:18 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] != '\0';
	return (dest);
}

int	main(void)
{
	char	*src = "teeeeeeeeest";
	char	*dest = "";
	int	n = 5;

	ft_strcpy(dest, src, n);
	while (dest[i])
	{
		printf("%c", dest[1]);
	}
}
