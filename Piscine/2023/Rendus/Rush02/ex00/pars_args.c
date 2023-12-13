/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalasbor <kirito042004@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:27:47 by hsolet            #+#    #+#             */
/*   Updated: 2023/07/30 22:08:47 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned long long	ft_atoi_check(char *str)
{
	int					i;
	unsigned long long	result;

	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i])
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (result);
}
