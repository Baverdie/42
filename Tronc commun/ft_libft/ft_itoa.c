/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:49:04 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/07 13:35:43 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_itoa(int n)
{
	char	*str;
	int	i;
	int	p;
	int	tmp;

	tmp = n;
	p = 0;
	i = 0;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		p++;
	}
	str = ft_calloc(p + 2, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 10)
		str[0] = n + 48;
	else
	{
		while (p >= 0)
		{
			str[i] = n / 10 + 48;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

int main()
{
	printf("itoa = %s", ft_itoa(100));
}