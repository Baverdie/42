/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:36:58 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/23 14:40:37 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexa(long long int n, char *base)
{
	int	c;

	c = 0;
	if (n < 0)
	{
		n *= -1;
		c += ft_putchar('-');
	}
	if (n < 16)
		c += ft_putchar(base[n]);
	else
	{
		c += ft_putnbr(n / 16);
		c += ft_putchar(base[n % 16]);
	}
	return (c);
}
