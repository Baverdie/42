/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:49:04 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/08 09:25:35 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_power(long int n)
{
	int	p;

	p = 0;
	if (n < 0)
	{
		n = n * -1;
		p++;
	}
	while (n >= 10)
	{
		n = n / 10;
		p++;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		p;
	long long int	nb;

	p = ft_power(n) + 1;
	nb = n;
	str = ft_calloc(p + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = 45;
		nb *= -1;
	}
	p--;
	while (p >= 0 && str[p] != 45)
	{
		str[p] = (nb % 10) + 48;
		nb = nb / 10;
		p--;
	}
	return (str);
}
