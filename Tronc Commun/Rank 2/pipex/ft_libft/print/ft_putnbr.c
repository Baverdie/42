/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <basverdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:36:10 by basverdi          #+#    #+#             */
/*   Updated: 2024/03/01 15:59:21 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr(long long int n)
{
	int	cntr;

	cntr = 0;
	if (n < 0)
	{
		n *= -1;
		cntr += ft_putchar('-');
	}
	if (n < 10)
		cntr += ft_putchar(n + 48);
	else
	{
		cntr += ft_putnbr(n / 10);
		cntr += ft_putchar(n % 10 + 48);
	}
	return (cntr);
}
