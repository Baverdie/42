/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:36:58 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/01 15:59:21 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthexa(long long int n, char *base)
{
	int	cntr;

	cntr = 0;
	if (n < 16)
		cntr += ft_putchar(base[n]);
	else
	{
		cntr += ft_puthexa(n / 16, base);
		cntr += ft_putchar(base[n % 16]);
	}
	return (cntr);
}
