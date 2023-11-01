/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basverdi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:46:46 by basverdi          #+#    #+#             */
/*   Updated: 2023/07/13 11:18:10 by basverdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a != 57 || b != 56)
		write(1, ", ", 2);
}

void	ft_verification(char a, char b, char c, char d)
{
	while (a <= 57)
	{
		while (b <= 56)
		{
			while (c <= 57)
			{
				while (d <= 57)
				{
					if (a <= b && ((a + b) <= (c + d)))
					{
						ft_write(a, b, c, d);
					}
					d++;
				}
				d = 48;
				c++;
			}
			c = 48;
			b++;
		}
		b = 48;
		a++;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = 48;
	b = 48;
	c = 48;
	d = 49;
	ft_verification(a, b, c, d);
}

int	main(void)
{
	ft_print_comb2();
}
