/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:32:09 by vgodart           #+#    #+#             */
/*   Updated: 2023/07/30 22:08:17 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

unsigned long long	ft_atoi(char *str)
{
	int					i;
	unsigned long long	result;

	result = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += str[i] - 48;
			i++;
		}
	}
	return (result);
}
