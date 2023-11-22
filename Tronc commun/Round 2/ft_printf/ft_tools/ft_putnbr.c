/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:36:10 by basverdi          #+#    #+#             */
/*   Updated: 2023/11/22 16:34:31 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	ft_putnbr(long long int n)
{
	int	c;

	c = 0;
	if (n == -2147483648)
		c += ft_putstr("-2147483648");
	if (n < 0)
	{
		n *= -1;
		c += ft_putchar('-');
	}
	if (n < 10)
		c += ft_putchar(n + 48);
	else
	{
		c += ft_putnbr(n / 10);
		c += ft_putchar(n % 10 + 48);
	}
	return (c);
}
