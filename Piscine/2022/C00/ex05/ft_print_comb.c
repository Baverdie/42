/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baverdie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:13:12 by baverdie          #+#    #+#             */
/*   Updated: 2022/07/15 22:44:35 by baverdie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_if_should(char c[3])
{
	if (c[0] == '7' && c[1] == '8' && c[2] == '9' )
	{
		write(1, &c[0], 3);
	}
	else if ((c[0] < c[1]) < c[2] && (c[0] != c[1]) != c[2])
	{
		write(1, &c[0], 3);
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	c[3];

	c[0] = '0' ;
	while (c[0] <= '7')
	{
		c[1] = c[0] + 1;
		while (c[1] <= '8')
		{
			c[2] = c[1] + 1;
			while (c[2] <= '9')
			{
				print_if_should(c);
				++c[2];
			}
			++c[1];
		}
		++c[0];
	}
}

//int	main(void)
//{
//	ft_print_comb();
//}
