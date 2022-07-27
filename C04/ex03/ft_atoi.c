/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <bastien.verdiervaissiere@gm      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 03:20:38 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/26 19:17:51 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio_ext.h>
#include <strings.h>

int	ft_atoi(char *str)
{
	int	i;
	int neg;

	neg = 1;
	i = 0;
	while (str[i] == ' ' ||  str[i] == '\f' || str[i] == '\n' )
		i++;

	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
		return(neg);
}
