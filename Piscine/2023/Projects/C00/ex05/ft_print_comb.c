/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:26:32 by basverdi          #+#    #+#             */
/*   Updated: 2023/07/12 16:59:09 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int a, int b, int c)
{
	a += 48;
	b += 48;
	c += 48;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != 55 || b != 56 || c != 57)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 1;
	c = 2;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				if (a < b && b < c)
				{
					ft_write(a, b, c);
					c++;
				}
			}
			b++;
		}
		a++;
	}
}
