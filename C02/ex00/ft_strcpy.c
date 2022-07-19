/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 06:10:23 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/18 06:30:18 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

//int	main(void)
//{
//	char	src[] = "abcde";
//	char	dest[250];
//	int	i = 0;
//
//	ft_strcpy(dest, src);
//	while (dest[i])
//	{
//		printf("%c", dest[i]);
//		i++;
//	}
//}
