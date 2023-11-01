/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 07:32:50 by kroussar          #+#    #+#             */
/*   Updated: 2022/07/31 07:36:33 by kroussar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	total;
	int	neg;

	neg = 1;
	total = 0;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	if (*str == '-' || *str == '+')
		neg = (*str++ == '-');
	while (*str && (*str >= '0' && *str <= '9'))
		total = total * 10 - (*str++ - '0');
	if (neg)
		return (total);
	return (-total);
}
