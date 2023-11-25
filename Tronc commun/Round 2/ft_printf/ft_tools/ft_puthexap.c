/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastienverdier-vaissiere <bastienverdie    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:25 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/23 14:40:24 by bastienverd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexap(unsigned long long f, char *base)
{
	int	c;

	c = 0;
	if (f < 16)
		c += ft_putchar(base[f]);
	else
	{
		c += ft_putnbr(f / 16);
		c += ft_putchar(base[f % 16]);
	}
	return (c);
}
